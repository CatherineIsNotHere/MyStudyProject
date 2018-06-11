/*
 * Created on Feb 17, 2005
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
package com.cliqr.gamedev;

import com.golden.gamedev.object.Background;
import com.golden.gamedev.object.background.ParallaxBackground;

/**
 * @author t535293
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
public class TileStudioParallaxBackground extends ParallaxBackground {

    public TileStudioParallaxBackground(Background[] backgrounds) {
        super(backgrounds);
    }

    public void update(long elapsedTime) {
        super.update(elapsedTime);
        Background[] bg = getParallaxBackground();
        for(int i = 0; i < bg.length; i++)
            bg[i].update(elapsedTime);
    }
}
