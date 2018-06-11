/*
 * Created on Feb 14, 2005
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
package com.cliqr.gamedev.tilestudio;

import java.awt.Color;
import java.awt.image.BufferedImage;
import java.io.InputStream;
import java.io.InputStreamReader;

import com.golden.gamedev.Game;
import com.golden.gamedev.object.background.TileBackground;
import com.thoughtworks.xstream.XStream;
import com.thoughtworks.xstream.io.xml.DomDriver;

/**
 * @author t535293
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
public class TileStudioHelper {

    public static TileStudioProject getTSP(String resource) {
        InputStream is = TileStudioHelper.class.getResourceAsStream(resource);
        if(is!=null) {
    		XStream xs = new XStream(new DomDriver());
    		xs.alias("project", TileStudioProject.class);
    		xs.alias("tileset", TileStudioProject.TileSet.class);
    		xs.alias("sequence", TileStudioProject.TileSet.Sequence.class);
    		xs.alias("frame", TileStudioProject.TileSet.Sequence.Frame.class);
    		xs.alias("map", TileStudioProject.TileSet.TileMap.class);
    		xs.alias("cell", TileStudioProject.TileSet.TileMap.Cell.class);
    		return (TileStudioProject) xs.fromXML(new InputStreamReader(is));
        } else {
            throw new TileStudioException("Resource not found: "+resource);
        }
    }

    public static TileBackground createTileBackground(Game game, TileStudioProject tsp, int tileSetIndex, int mapIndex) {
        TileStudioProject.TileSet ts = tsp.tileSetList[tileSetIndex];
        TileStudioProject.TileSet.TileMap tm = ts.mapList[mapIndex];

        game.setMaskColor(new Color(ts.transparentRed, ts.transparentGreen, ts.transparentBlue));
        BufferedImage[] images = game.getImages(ts.tileBitmap, ts.horizontalTileCount, ts.verticalTileCount, true);
        
        int[][] map = new int[tm.width][tm.height];
        for(int y=0;y<tm.height;y++) {
            for(int x=0;x<tm.width;x++) {
                int tile = tm.cellList[y*tm.width+x].tileNumber;
                map[x][y] = tile-1;
            }
        }

        TileBackground tb = new TileBackground(images, map);
        return tb;
    }    
}