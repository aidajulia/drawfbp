package com.jpaulmorrison.graphics;

import java.awt.Color;
import java.awt.Graphics;

	public class PersonBlock extends Block {
		
		PersonBlock (Diagram ctlr){
			super(ctlr);
			type = Block.Types.PERSON_BLOCK;
			width = 40;
		  	height = 60;
		  	//calcEdges();
		}
		
		@Override
		void draw (Graphics g) {
			if (!visible && this != driver.selBlock) {
				showZones(g);
				return;
			}
			g.setColor(Color.LIGHT_GRAY);
			g.fillRect(cx - width / 2, cy - height / 2, width, height);
			g.setColor(Color.BLACK);
			g.drawOval(cx - 8, cy - height/2 + 2, 16, 20);
			if (this == driver.selBlock)
				g.setColor(DrawFBP.ly); // light yellow
				else
				g.setColor(DrawFBP.lb); // light turquoise			
			
			g.fillOval(cx - 7, cy - height/2 + 3, 14, 18);
			g.setColor(Color.BLACK);
			g.drawLine(cx, cy - height/2 + 20, cx, cy + 4);  // vert
			g.drawLine(cx, cy + 4, cx - 12, cy + height/2);  // legs
			g.drawLine(cx, cy + 4, cx + 12, cy + height/2);
			g.drawLine(cx, cy - 2, cx - 14, cy + 5);  // arms
			g.drawLine(cx, cy - 2, cx + 14, cy + 5);
			//showZones(g);
			calcDiagMaxAndMin(cx - width / 2, cx + width / 2,
					cy - height / 2, cy + height / 2);
			if (description != null) {
				centreDesc(g);
			}
			}
}
