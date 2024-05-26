#pragma once

#include <cassert>
#include <cmath>

namespace iwin::layout {

    struct rect {
        int xmin, ymin, xmax, ymax;
        int width() { return xmax - xmin; }
        int height() { return ymax - ymin; }
    };

    enum cut_direction {
        CUT_LEFT,
        CUT_RIGHT,
        CUT_TOP,
        CUT_BOTTOM,
    };

    // cut rectangle in user provided direction
    inline rect cut(rect parent, rect* remainder, cut_direction dir, int size) {
        rect child = parent;
        switch (dir) {
            case CUT_LEFT: child.xmax = parent.xmin + size; parent.xmin += size; break;
            case CUT_RIGHT: child.xmin = parent.xmax - size; parent.xmax -= size; break;
            case CUT_TOP: child.ymax = parent.ymin + size; parent.ymin += size; break;
            case CUT_BOTTOM: child.ymin = parent.ymax - size; parent.ymax -= size; break; 
        }

        *remainder = parent;
        return child;
    }

    inline rect cut(rect *parent, cut_direction dir, int size) {
        return cut(*parent, parent, dir, size);
    }

    struct static_layout {
        rect bounds;
        int size;
        int item_size;
        int divisions;
        int is_vertical;
    };

    struct space {
        rect bounds;
        rect remaining;
        static_layout layout;
    };

    inline void fixed_row(space *s, int height, int cols) {
        s->layout.size = height;
        s->layout.item_size = s->bounds.width() / cols;
        s->layout.is_vertical = false;
        s->layout.divisions = cols;
        s->layout.bounds = cut(&s->remaining, CUT_TOP, height);
    }

    inline rect next_widget_rect(space *s) {
        return cut(&s->layout.bounds, CUT_LEFT, s->layout.item_size);
    }
}