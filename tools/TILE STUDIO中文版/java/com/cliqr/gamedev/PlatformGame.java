/*
 * Created on Feb 14, 2005
 * 
 */
package com.cliqr.gamedev;

import java.awt.Dimension;
import java.awt.Graphics2D;
import java.awt.event.KeyEvent;

import com.cliqr.gamedev.tilestudio.TileStudioHelper;
import com.cliqr.gamedev.tilestudio.TileStudioProject;
import com.golden.gamedev.Game;
import com.golden.gamedev.GameLoader;
import com.golden.gamedev.engine.graphics.FullScreenMode;
import com.golden.gamedev.engine.graphics.WindowedMode;
import com.golden.gamedev.funbox.GameSettings;

/**
 * @author t535293
 * 
 * TODO: Document me!
 *  
 */
public class PlatformGame extends Game {
    //    { distribute = true; }

    private int x, y;

    private TileStudioBackground bBack;
    private TileStudioBackground bFront;
    private TileStudioParallaxBackground parallaxBackground;

    public static void main(String[] args) {
        GameSettings settings = new GameSettings() {
            public void start() {
                // here goes the usual way of game initialization
                GameLoader game = new GameLoader();

                game.setup(new PlatformGame() {
                    protected void initEngine() {
                        super.initEngine();
                        // set active sound base on user setting
                        bsSound.setActive(isSound());
                        bsMusic.setActive(isSound());
                    }
                }, new Dimension(320, 240), isFullScreen(), isBufferStrategy());

                game.start();
            }
        };
    }

    public void initResources() {
        setTitle("Spud");
        // TileStudioProject tsp = TileStudioHelper.getTSP("/spud.xml");
        TileStudioProject tsp = TileStudioHelper.getTSP("/ScrollDemo.xml");
        // background = TileStudioHelper.createTileBackground(this, tsp, 1, 0);
        bBack = new TileStudioBackground(this, tsp, 1, 0);
        bFront = new TileStudioBackground(this, tsp, 0, 0);
        parallaxBackground = new TileStudioParallaxBackground(new TileStudioBackground[] { bBack, bFront });
    }

    public void update(long elapsedTime) {
        if (keyDown(KeyEvent.VK_LEFT)) {
            x -= 4;
        } else if (keyDown(KeyEvent.VK_RIGHT)) {
            x += 4;
        }
        if (keyDown(KeyEvent.VK_UP)) {
            y -= 4;
        } else if (keyDown(KeyEvent.VK_DOWN)) {
            y += 4;
        }
        parallaxBackground.setLocation(x, y);
        parallaxBackground.update(elapsedTime);
    }

    public void render(Graphics2D g) {
        parallaxBackground.render(g);
    }

    protected void setTitle(String title) {
        if (bsGraphics instanceof WindowedMode) {
            ((WindowedMode) bsGraphics).getFrame().setTitle(title);
        } else if (bsGraphics instanceof FullScreenMode) {
            ((FullScreenMode) bsGraphics).getFrame().setTitle(title);
        }
    }
}