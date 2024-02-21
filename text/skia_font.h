// LAF Text Library
// Copyright (c) 2024  Igara Studio S.A.
//
// This file is released under the terms of the MIT license.
// Read LICENSE.txt for more information.

#ifndef LAF_TEXT_SKIA_FONT_H_INCLUDED
#define LAF_TEXT_SKIA_FONT_H_INCLUDED
#pragma once

#include "text/font.h"

#include "include/core/SkFont.h"

namespace text {

  class SkiaFont : public Font {
  public:
    SkiaFont(const SkFont& skFont);
    ~SkiaFont();

    bool isValid() const;
    FontType type() override;
    float metrics(FontMetrics* metrics) const override;
    int height() const override;
    int textLength(const std::string& str) const override;
    bool isScalable() const override;
    void setSize(int size) override;
    void setAntialias(bool antialias) override;
    bool hasCodePoint(int codepoint) const override;

    SkFont& skFont() { return m_skFont; }

  private:
    SkFont m_skFont;
  };

} // namespace text

#endif
