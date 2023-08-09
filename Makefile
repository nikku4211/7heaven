#
# A Makefile that compiles all .c and .s files in "src" and "res" 
# subdirectories and places the output in a "obj" subdirectory
#

# If you move this project you can change the directory 
# to match your GBDK root directory (ex: GBDK_HOME = "C:/GBDK/"

TOOLDIR = tools

RGBDS_HOME = ../rgbds
#RGBGFX = rgbgfx

#RGBGFXFLAGSSPR = -Z
#RGBGFXFLAGSTIL =  
#RGBGFXFLAGSMAP = -T

RGBASM = $(RGBDS_HOME)/win64/rgbasm

RGB2SDAS = python $(TOOLDIR)/rgb2sdas.py
RGB2SDASFLAGS = -b 0

GBDK_HOME = ../GBDK/

ROMUSAGE = ../romusage/romusage

LCC = $(GBDK_HOME)bin/lcc 
PNG2ASSET = $(GBDK_HOME)bin/png2asset

P2AFLAGSSPR = -tiles_only -map -bin
P2AFLAGSTIL = -tiles_only -map -bin
P2AFLAGSMAP = -maps_only -map -bin

PNGTOCHR = $(TOOLDIR)/pngtochr

P2CFLAGSTIL = -p 0,1
P2CFLAGSSPR = -p 0,1 -W 8 -H 16

ifeq ($(OS), Windows_NT)
DOTEXE:=.exe
PY:=python3
else
DOTEXE:=
PY:=
endif

# You can set flags for LCC here
# For example, you can uncomment the line below to turn on debug output
LCCFLAGS = -Wm-yc -Wm-ys -Wl-j -Wm-yS -debug # -Wf--verbose 

# You can set the name of the .gb ROM file here
PROJECTNAME    = 7heaven

SRCDIR      = src
OBJDIR      = obj
RESDIR      = res
LEVDIR			= level
MUSDIR			= music
IMAGEFILES  = $(foreach dir,$(RESDIR),$(notdir $(wildcard $(dir)/*.png)))
#LEVELFILES = $(foreach dir,$(LEVDIR),$(notdir $(wildcard $(dir)/*.csv)))
BINS	    = $(OBJDIR)/$(PROJECTNAME).gb
CSOURCES    = $(foreach dir,$(SRCDIR),$(notdir $(wildcard $(dir)/*.c))) $(foreach dir,$(RESDIR),$(notdir $(wildcard $(dir)/*.c))) $(foreach dir,$(LEVDIR),$(notdir $(wildcard $(dir)/*.c))) $(foreach dir,$(MUSDIR),$(notdir $(wildcard $(dir)/*.c)))
ASMSOURCES  = $(foreach dir,$(SRCDIR),$(notdir $(wildcard $(dir)/*.s)))
RGBASMSOURCES	=	$(foreach dir,$(MUSDIR),$(notdir $(wildcard $(dir)/*.asm)))
#LEVELS		 = 	$(LEVELFILES:%.csv=$(LEVDIR)/%.c) $(LEVELFILES:%.csv=$(LEVDIR)/%.h)
PNGS       =	$(IMAGEFILES:%.png=$(RESDIR)/%.2bpp)
OBJS			 =	$(CSOURCES:%.c=$(OBJDIR)/%.o) $(ASMSOURCES:%.s=$(OBJDIR)/%.o) $(RGBASMSOURCES:%.asm=$(OBJDIR)/%.o)
RGOBJS		 =	$(RGBASMSOURCES:%.asm=$(OBJDIR)/%.obj)

all:	prepare $(BINS)

compile.bat: Makefile
	@echo "REM Automatically generated from Makefile" > compile.bat
	@make -sn | sed y/\\//\\\\/ | grep -v make >> compile.bat

# Compile .png files in "res/" to row-major 2bpp files
$(RESDIR)/%.2bpp:	$(RESDIR)/%.png
	$(PNGTOCHR) $(P2CFLAGSTIL) -i $< -o $@
	
# Compile certain .png files in "res/" to column-major 2bpp files
$(RESDIR)/%spr.2bpp:	$(RESDIR)/%spr.png
	$(PNGTOCHR) $(P2CFLAGSSPR) -i $< -o $@
#	$(PNG2ASSET) $< $(P2AFLAGSSPR) -c $@
#	tools/gfx --png $< --interleave -o $@ $@

# Compile .csv files in "level/" to C arrays
#$(LEVDIR)/%.c:	$(LEVDIR)/%.csv
#	$(PY) $(TOOLDIR)/csvtoc.py -i $< > $@
	
#$(LEVDIR)/%.h: $(LEVDIR)/%.csv
#	$(PY) $(TOOLDIR)/csvtoh.py -i $< > $@

# Compile .png files in "res/" to row-major 2bpp files
#$(RESDIR)/%.c:	$(RESDIR)/%.png
#	$(RGBGFX) $< $(RGBGFXFLAGSTIL) -o $@
	
# Compile certain .png files in "res/" to column-major 2bpp files
#$(RESDIR)/%spr.2bpp:	$(RESDIR)/%spr.png
#	$(RGBGFX) $< $(RGBGFXFLAGSSPR) -o $@
	
# Compile .png files in "level/" to tilemap files
#$(LEVDIR)/%.tilemap:	$(LEVDIR)/%.png
#	$(RGBGFX) $< $(RGBGFXFLAGSMAP) -o $@
	
# Compile .c files in "src/" to .o object files
$(OBJDIR)/%.o:	$(SRCDIR)/%.c
	$(LCC) $(LCCFLAGS) -c -o $@ $<

# Compile .c files in "res/" to .o object files
$(OBJDIR)/%.o:	$(RESDIR)/%.c
	$(LCC) $(LCCFLAGS) -c -o $@ $<
	
# Compile .c files in "level/" to .o object files
$(OBJDIR)/%.o:	$(LEVDIR)/%.c
	$(LCC) $(LCCFLAGS) -c -o $@ $<

# Compile .c files in "level/" to .o object files
$(OBJDIR)/%.o:	$(MUSDIR)/%.c
	$(LCC) $(LCCFLAGS) -c -o $@ $<
	
$(OBJDIR)/%.obj:	$(MUSDIR)/%.asm
	$(RGBASM) -i.. -DGBDK -o$@ $<
	
$(OBJDIR)/%.o:	$(OBJDIR)/%.obj
	$(RGB2SDAS) $(RGB2SDASFLAGS) -o$@ $<

# Compile .s assembly files in "src/" to .o object files
$(OBJDIR)/%.o:	$(SRCDIR)/%.s
	$(LCC) $(LCCFLAGS) -c -o $@ $<

# If needed, compile .c files in "src/" to .s assembly files
# (not required if .c is compiled directly to .o)
$(OBJDIR)/%.s:	$(SRCDIR)/%.c
	$(LCC) $(LCCFLAGS) -S -o $@ $<

# Link the compiled object files into a .gb ROM file
$(BINS):	$(RGOBJS) $(PNGS) $(OBJS)
	$(LCC) $(LCCFLAGS) -o $(BINS) $(OBJS)

prepare:
	mkdir -p $(OBJDIR)

clean:
#	rm -f  *.gb *.ihx *.cdb *.adb *.noi *.map
	rm -f  $(OBJDIR)/*.*
	
cleangfx:
	rm -f  $(RESDIR)/*.2bpp
	
cleanlvl:
	rm -f  $(LEVDIR)/*.c
	rm -f  $(LEVDIR)/*.h

romused:
	$(ROMUSAGE) $(OBJDIR)/$(PROJECTNAME).map -g