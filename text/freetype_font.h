// LAF Text Library
// Copyright (C) 2020-2024  Igara Studio S.A.
// Copyright (C) 2016-2017  David Capello
//
// This file is released under the terms of the MIT license.
// Read LICENSE.txt for more information.

#ifndef LAF_TEXT_FREETYPE_FONT_H_INCLUDED
#define LAF_TEXT_FREETYPE_FONT_H_INCLUDED
#pragma once

#include "ft/hb_face.h"
#include "ft/lib.h"
#include "text/font.h"

namespace text {
  class Font;

  class FreeTypeFont : public Font {
  public:
    using Face = ft::Face;

    FreeTypeFont(ft::Lib& lib,
                 const char* filename,
                 const int height);
    ~FreeTypeFont();

    bool isValid() const;
    FontType type() override;
    int height() const override;
    int textLength(const std::string& str) const override;
    bool isScalable() const override;
    void setSize(int size) override;
    void setAntialias(bool antialias) override;
    bool hasCodePoint(int codepoint) const override;

    Face& face() { return m_face; }

    static base::Ref<FreeTypeFont> LoadFont(
      ft::Lib& lib,
      const char* filename,
      const int height);

  private:
    mutable Face m_face;
  };

} // namespace text

#endif