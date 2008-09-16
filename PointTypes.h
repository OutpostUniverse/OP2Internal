

#ifndef PointTypes_H
#define PointTypes_H


namespace OP2ForcedExport
{
	// Common Types

	struct Point
	{
		int x;
		int y;
	};

	struct Rect
	{
		union
		{
			struct
			{
				int x1;
				int y1;
				int x2;
				int y2;
			};
			struct
			{
				Point topLeft;
				Point bottomRight;
			};
		};
	};

}	// End namespace


#endif
