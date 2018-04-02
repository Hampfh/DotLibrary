#pragma once

namespace DTL {

	struct colorTemplate {
		int r = 255;
		int g = 255;
		int b = 255;
	};

	struct coordinateTemplate {
		int x = 0;
		int y = 0;
	};

	struct sizeTemplate {
		int w;
		int h;
	};

	enum Flags {
		DTL_HIDE_CMD = 0x01,
		DTL_RESIZABLE_WINDOW = 0x02,
		DTL_HIDDEN_WINDOW = 0x04
	};

}