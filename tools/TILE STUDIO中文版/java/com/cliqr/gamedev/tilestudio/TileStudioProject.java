/*
 * Created on Feb 14, 2005
 *
 */
package com.cliqr.gamedev.tilestudio;

/**
 * @author Paul Rene Jørgensen, <paulrene@gmail.com>
 *
 * This class acts like a Value Object and is populated with the XML from Tile Studio.
 * XStream does this automatically. Here are some example code to load in the XML.
 * 
 * {code}
 * XStream xs = new XStream(new DomDriver());
 * xs.alias("project", Project.class);
 * xs.alias("tileset", Project.TileSet.class);
 * xs.alias("sequence", Project.TileSet.Sequence.class);
 * xs.alias("frame", Project.TileSet.Sequence.Frame.class);
 * xs.alias("map", Project.TileSet.TileMap.class); xs.alias("cell", Project.TileSet.TileMap.Cell.class);
 * Project p = (Project) xs.fromXML(new InputStreamReader(Test.class.getResourceAsStream("/spud.xml")));
 * {code}
 * 
 */
public class TileStudioProject {
    public TileStudioProject() { }
	public String name;
	public String author;
	public String notes;
	public String copyright;
	public String date;
	public String time;
	public String generator;
	public int tileSetCount;
	public TileSet[] tileSetList;
	
	public class TileSet {
	    public TileSet() { }
		public int index;
		public String identifier;
		public int tileWidth;
		public int tileHeight;
		public String tileBitmap;
		public int horizontalTileCount;
		public int verticalTileCount;
		public int tileSetBitmapWidth;
		public int tileSetBitmapHeight;
		public int transparentRed;
		public int transparentGreen;
		public int transparentBlue;
		public int overlap;
		public int tileCount;
		public int sequenceCount;
		public Sequence[] sequenceList;
		public int mapCount;
		public TileMap[] mapList;
		
		public class Sequence {
		    public Sequence() { }
			public int index;
			public String spriteName;
			public int spriteNumber;
			public int spriteLength;
			public int frameCount;
			public Frame[] frameList;
			
			public class Frame {
			    public Frame() { }
				public int frameDelay;
				public int tileNumber;				
			}
		}
		
		public class TileMap {
		    public TileMap() { }
			public int index;
			public String identifier;
			public int width;
			public int height;
			public String scrollX;
			public String scrollY;
			public Cell[] cellList;
			
			public class Cell {
			    public Cell() { }
				public int tileNumber;
				public int bounds;
				public int mapCode;
			}
		}
	}
}