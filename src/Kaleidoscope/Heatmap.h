/* -*- mode: c++ -*-
 * Kaleidoscope-Heatmap -- Heatmap LED effect for Kaleidoscope.
 * Copyright (C) 2016, 2017  Gergely Nagy
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <Kaleidoscope.h>
#include <Kaleidoscope-LEDControl.h>

namespace KaleidoscopePlugins {
class Heatmap : public LEDMode {
  public:
    Heatmap (void);

    virtual void begin (void) final;

    static uint16_t updateDelay;

    virtual void update (void) final;
  private:
    static uint8_t heatmap[ROWS][COLS];
    static uint16_t totalKeys;
    static uint8_t highestCount;
    static uint32_t endTime;

    static const float heatColors[][3];

    static void shiftStats (void);
    static cRGB computeColor (float v);

    static Key eventHook (Key mappedKey, byte row, byte col, uint8_t keyState);
    static void loopHook (bool postClear);
};
};

extern KaleidoscopePlugins::Heatmap HeatmapEffect;
