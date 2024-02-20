// LAF Text Library
// Copyright (C) 2019-2024  Igara Studio S.A.
//
// This file is released under the terms of the MIT license.
// Read LICENSE.txt for more information.

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "os/paint.h"
#include "os/skia/skia_helpers.h"
#include "os/skia/skia_surface.h"
#include "os/system.h"
#include "text/draw_text.h"
#include "text/font_mgr.h"
#include "text/skia_font.h"

#include "include/core/SkTextBlob.h"
#include "include/utils/SkTextUtils.h"
#include "modules/skshaper/include/SkShaper.h"

namespace text {

void draw_text(
  os::Surface* surface,
  const FontRef& font,
  const std::string& text,
  const gfx::Point& pos,
  const os::Paint* paint,
  const TextAlign textAlign,
  DrawTextDelegate* delegate)
{
  if (!font || font->type() != FontType::Native)
    return;

  SkTextUtils::Draw(
    &static_cast<os::SkiaSurface*>(surface)->canvas(),
    text.c_str(), text.size(),
    SkTextEncoding::kUTF8,
    SkIntToScalar(pos.x),
    SkIntToScalar(pos.y),
    static_cast<SkiaFont*>(font.get())->skFont(),
    (paint ? paint->skPaint(): SkPaint()),
    (SkTextUtils::Align)textAlign);
}

} // namespace text