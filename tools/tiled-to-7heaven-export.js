/*
 * tiled-to-7heaven-export.js
 *
 * This extension adds the "7heaven C array" type to the "Export As" menu,
 * which generates C arrays that can be loaded directly into 7heaven as an "include"
 * 
 * This tool was adapted from the SNES version of the GBA Plugin that is Copyright (c) 2020 Jay van Hutten
 * That SNES version is Copyright (c) 2021 @KhazWolf
 * This C version is Copyright (c) 2023 Nikku4211
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 */

var customCArrayMapFormat = {
	name: "7heaven C array",
  extension: "c",
  write:
		function(p_map, p_fileName){
			console.time("Export completed in");
			
			// Only allow valid map sizes to be parsed
			if (p_map.width % 32 != 0) {
				return "Export failed: Invalid map size! Map width must be a multiple of 32.";
			}

			// Standard screenblock size for SNES
			const SCREENBLOCKWIDTH = 32;
			const SCREENBLOCKHEIGHT = 32;
			
			// Split full filename path into the filename (without extension) and the directory
      var fileBaseName = FileInfo.completeBaseName(p_fileName).replace(/[^a-zA-Z0-9-_]/g, "_");
      var filePath = FileInfo.path(p_fileName)+"/";

      // Replace the ‘/’ characters in the file path for ‘\’ on Windows
      filePath = FileInfo.toNativeSeparators(filePath);
			
			var sourceFileData = "";
			var sourceFileData2 = "";
			
			sourceFileData +="const unsigned char "+fileBaseName+"_"+p_map.layerAt(0).name+"[] = {\n";
			sourceFileData2 +="const unsigned char "+fileBaseName+"_"+p_map.layerAt(1).name+"[] = {\n";
			
				let currentLayer = p_map.layerAt(0);

				// Replace special characters for an underscore
				let currentLayerName = currentLayer.name.replace(/[^a-zA-Z0-9-_]/g, "_");
				
				let screenBlockCountX = currentLayer.width/SCREENBLOCKWIDTH;
        let screenBlockCountY = currentLayer.height/SCREENBLOCKHEIGHT;
				
				if (currentLayer.isTileLayer) {
					for (let y = 0; y < currentLayer.height; ++y) {
						for (let x = 0; x < currentLayer.width; ++x) {
							let currentTileX = x;
							let currentTileY = y;
							let currentTile = currentLayer.cellAt(currentTileX, currentTileY);
							var currentTileID = currentTile.tileId;

							// Default to 0 for blank tiles
							if (currentTileID == "-1") {
								sourceFileData += "0,";
							} else {
								sourceFileData += currentTileID+",";
							}
						}
						sourceFileData += "\n";
					}
				}
				
				currentLayer = p_map.layerAt(1);
				
				if (currentLayer.isTileLayer) {
					for (let j = 0; j < screenBlockCountY; ++j) {
            for (let k = 0; k < screenBlockCountX; ++k) {
							for (let y = 0; y < currentLayer.height; ++y) {
								for (let x = 0; x < SCREENBLOCKWIDTH; ++x) {
									let currentTileX = x+(SCREENBLOCKWIDTH*k);
                  let currentTileY = y;
									let currentTile = currentLayer.cellAt(currentTileX, currentTileY);
									var currentTileID = currentTile.tileId;

									// Default to 0 for blank tiles
									if (currentTileID == "-1") {
										sourceFileData2 += "0,";
									} else {
										sourceFileData2 += currentTileID+",";
									}
								}
								sourceFileData2 += "\n";
							}
						}
						sourceFileData2 += "\n";
					}
				}
			sourceFileData +="};";
			sourceFileData2 +="};";
			
			var sourceHeaderData = "#ifndef __"+fileBaseName+"_"+p_map.layerAt(0).name+"_h_INCLUDE\n#define __"+fileBaseName+"_"+p_map.layerAt(0).name+"_h_INCLUDE\nextern const unsigned char "+fileBaseName+"_"+p_map.layerAt(0).name+"[];\n#endif";
			var sourceHeaderData2 = "#ifndef __"+fileBaseName+"_"+p_map.layerAt(1).name+"_h_INCLUDE\n#define __"+fileBaseName+"_"+p_map.layerAt(1).name+"_h_INCLUDE\nextern const unsigned char "+fileBaseName+"_"+p_map.layerAt(1).name+"[];\n#endif";
			
			// Write source data to disk
			var sourceFile = new TextFile(filePath+fileBaseName+"_"+p_map.layerAt(0).name+".c", TextFile.WriteOnly);
			sourceFile.write(sourceFileData);
			sourceFile.commit();
			console.log("Tilemap exported to "+filePath+fileBaseName+"_"+p_map.layerAt(0).name+".c");
			
			var sourceHeader = new TextFile(filePath+fileBaseName+"_"+p_map.layerAt(0).name+".h", TextFile.WriteOnly);
			sourceHeader.write(sourceHeaderData);
			sourceHeader.commit();
			console.log("and "+filePath+fileBaseName+"_"+p_map.layerAt(0).name+".h");
			
			var sourceFile2 = new TextFile(filePath+fileBaseName+"_"+p_map.layerAt(1).name+".c", TextFile.WriteOnly);
			sourceFile2.write(sourceFileData2);
			sourceFile2.commit();
			console.log("Collision map exported to "+filePath+fileBaseName+"_"+p_map.layerAt(1).name+".c");
			
			var sourceHeader2 = new TextFile(filePath+fileBaseName+"_"+p_map.layerAt(1).name+".h", TextFile.WriteOnly);
			sourceHeader2.write(sourceHeaderData2);
			sourceHeader2.commit();
			console.log("and "+filePath+fileBaseName+"_"+p_map.layerAt(1).name+".h");

			console.timeEnd("Export completed in");
		}
}

tiled.registerMapFormat("7heaven C Array", customCArrayMapFormat)