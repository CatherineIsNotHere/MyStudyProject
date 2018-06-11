/*
 * Created on Feb 16, 2005
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
package com.cliqr.gamedev;

import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.image.BufferedImage;

import com.cliqr.gamedev.tilestudio.TileStudioProject;
import com.golden.gamedev.Game;
import com.golden.gamedev.object.background.AbstractTileBackground;

/**
 * @author t535293
 * 
 * TODO To change the template for this generated type comment go to Window -
 * Preferences - Java - Code Style - Code Templates
 */
public class TileStudioBackground extends AbstractTileBackground {
    private int[][] tileMap;
    private int[][] tileCode;
    private int[][] tileBounds;
    private BufferedImage[] tileImages;
    private TileStudioProject.TileSet.Sequence[] sequenceList;
    private int[] currentSequenceFrame;
    private int[] currentSequenceFrameDelay;

    public TileStudioBackground(Game game, TileStudioProject tsp, int tileSetIndex, int mapIndex) {
        super(tsp.tileSetList[tileSetIndex].mapList[mapIndex].width, tsp.tileSetList[tileSetIndex].mapList[mapIndex].height, tsp.tileSetList[tileSetIndex].tileWidth, tsp.tileSetList[tileSetIndex].tileHeight);

        TileStudioProject.TileSet ts = tsp.tileSetList[tileSetIndex];
        TileStudioProject.TileSet.TileMap tm = ts.mapList[mapIndex];
        sequenceList = ts.sequenceList;
        currentSequenceFrame = new int[sequenceList.length];
        currentSequenceFrameDelay = new int[sequenceList.length];

        game.setMaskColor(new Color(ts.transparentRed, ts.transparentGreen, ts.transparentBlue));
        tileImages = game.getImages(ts.tileBitmap, ts.horizontalTileCount, ts.verticalTileCount, true);

        tileMap = new int[tm.width][tm.height];
        tileCode = new int[tm.width][tm.height];
        tileBounds = new int[tm.width][tm.height];
        for (int y = 0; y < tm.height; y++) {
            for (int x = 0; x < tm.width; x++) {
                int tile = tm.cellList[y * tm.width + x].tileNumber;
                int code = tm.cellList[y * tm.width + x].mapCode;
                int bounds = tm.cellList[y * tm.width + x].bounds;
                tileMap[x][y] = tile;
                tileCode[x][y] = code;
                tileBounds[x][y] = bounds;
            }
        }
    }

    public void renderTile(Graphics2D g, int tileX, int tileY, int x, int y) {
        int tileIndex = tileMap[tileX][tileY];
        if (tileIndex >= 0) {
            if (tileIndex > 0) {
                g.drawImage(tileImages[tileIndex - 1], x, y, null);
            }
        } else {
            int sequenceIndex = Math.abs(tileIndex);
            TileStudioProject.TileSet.Sequence.Frame[] frameList = sequenceList[sequenceIndex - 1].frameList;
            g.drawImage(tileImages[frameList[currentSequenceFrame[sequenceIndex - 1]].tileNumber], x, y, null);
        }
    }

    public void update(long elapsedTime) {
        if(sequenceList.length>0) {
	        for(int n=0;n<sequenceList.length;n++) {
	            if(sequenceList[n].frameList[currentSequenceFrame[n]].frameDelay==0) {
	                currentSequenceFrame[n] = (currentSequenceFrame[n] + 1) % (sequenceList[n].frameList.length-1);
	            } else {
		            while(currentSequenceFrameDelay[n]<=0) {
		                currentSequenceFrame[n] = (currentSequenceFrame[n] + 1) % (sequenceList[n].frameList.length-1);
		                currentSequenceFrameDelay[n] += sequenceList[n].frameList[currentSequenceFrame[n]].frameDelay;
		            }
		            currentSequenceFrameDelay[n]-=elapsedTime;	                
	            }
	        }
        }
    }
}