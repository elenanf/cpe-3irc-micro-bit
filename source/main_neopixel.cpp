/*
The MIT License (MIT)

Copyright (c) 2016 British Broadcasting Corporation.
This software is provided by Lancaster University by arrangement with the BBC.

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#include "MicroBit.h"
#include "neopixel.h"

MicroBit uBit;

neopixel_strip_t m_strip;
uint8_t dig_pin_num = 3;
uint8_t leds_per_strip = 2;

int main()
{
    uBit.init();
    
    neopixel_init(&m_strip, dig_pin_num, leds_per_strip);
    neopixel_clear(&m_strip);


    while(true){
        neopixel_set_color_and_show(&m_strip, 1, 0, 0, 255);
        uBit.sleep(1000);
        neopixel_set_color_and_show(&m_strip, 1, 255, 255, 255);
        uBit.sleep(1000);
        neopixel_set_color_and_show(&m_strip, 1, 255, 0, 0);
        uBit.sleep(1000);
    }

    //clear and remove strip
    neopixel_clear(&m_strip);
    neopixel_destroy(&m_strip);

    release_fiber();
}

