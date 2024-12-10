/*
 * Copyright (c) 2022, Andreas Kling <andreas@ladybird.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibWeb/Layout/SVGSVGBox.h>
#include <LibWeb/Painting/PaintableBox.h>

namespace Web::Painting {

class SVGSVGPaintable final : public PaintableBox {
    GC_CELL(SVGSVGPaintable, PaintableBox);
    GC_DECLARE_ALLOCATOR(SVGSVGPaintable);

public:
    static GC::Ref<SVGSVGPaintable> create(Layout::SVGSVGBox const&);

    virtual void before_children_paint(PaintContext&, PaintPhase) const override;
    virtual void after_children_paint(PaintContext&, PaintPhase) const override;

    Layout::SVGSVGBox const& layout_box() const;

    static void paint_svg_box(PaintContext& context, PaintableBox const& svg_box, PaintPhase phase);
    static void paint_descendants(PaintContext& context, PaintableBox const& paintable, PaintPhase phase);

protected:
    SVGSVGPaintable(Layout::SVGSVGBox const&);
};

}
