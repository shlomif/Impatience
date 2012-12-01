#ifndef GUI_AREA_H_INCLUDED
#define GUI_AREA_H_INCLUDED

namespace GUI
{
    class Area
    {
    public:
        int x;
        int y;
        int w;
        int h;

        Area(const int = 0, const int = 0, const int = 0, const int = 0);
    };
}

#endif
