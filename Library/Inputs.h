#ifndef POLARIS__INPUTS_H
#define POLARIS__INPUTS_H
// #include <Window.h>


namespace Polaris{
    class InputStream{ 
        public:
                InputStream();
        private:
            unsigned int _buffer[256]; // key's are represented an int value [values in InputHanler::KB_KEYCODE]
    };
    
    // @args
    // @param capture: the window to capture input from (you can capture input from multiple windows)
    // @param type: the type of input to capture (keyboard, mouse, joystick, etc)
    class InputHandler{
        public:
            
            // https://gist.github.com/rickyzhang82/8581a762c9f9fc6ddb8390872552c250
            enum class KB_KEYCODE{ 
                ESCAPE          = 9,
                ONE             = 10, 
                TWO             = 11, 
                THREE           = 12, 
                FOUR            = 13, 
                FIVE            = 14, 
                SIX             = 15,
                SEVEN           = 16, 
                EIGHT           = 17, 
                NINE            = 18, 
                ZERO            = 19, 
                MINUS           = 20, 
                EQUALS          = 21, 
                BACKSPACE       = 22,
                TAB             = 23, 
                Q               = 24, 
                W               = 25, 
                E               = 26, 
                R               = 27, 
                T               = 28, 
                Y               = 29, 
                U               = 30, 
                I               = 31, 
                O               = 32, 
                P               = 33,
                LEFT_BRACKET    = 34, 
                RIGHT_BRACKET   = 35, 
                A               = 38, 
                S               = 39, 
                D               = 40, 
                F               = 41, 
                G               = 42, 
                H               = 43,
                J               = 44, 
                K               = 45, 
                L               = 46, 
                SEMICOLON       = 47, 
                APOSTROPHE      = 48, 
                ENTER           = 49,
                LEFT_SHIFT      = 50, 
                BACKSLASH       = 51,
                Z               = 52, 
                X               = 53,
                C               = 54, 
                V               = 55, 
                B               = 56, 
                N               = 57, 
                M               = 58, 
                COMMA           = 59, 
                PERIOD          = 60, 
                FORWARD_SLASH   = 61,
                RIGHT_SHIFT     = 62, 
                KEYPAD_MULTIPLY = 63, 
                CAPS_LOCK       = 66, 
                F1              = 67, 
                F2              = 68, 
                F3              = 69, 
                F4              = 70, 
                F5              = 71, 
                F6              = 72, 
                F7              = 73, 
                F8              = 74, 
                F9              = 75, 
                F10             = 76, 
                NUM_LOCK        = 77, 
                SCROLL_LOCK     = 78, 
                KEYPAD_7        = 79, 
                KEYPAD_8        = 80, 
                KEYPAD_9        = 81,
                KEYPAD_SUBTRACT = 82,
                KEYPAD_4        = 83, 
                KEYPAD_5        = 84, 
                KEYPAD_6        = 85,
                KEYPAD_ADD      = 86, 
                KEYPAD_1        = 87,
                KEYPAD_2        = 88, 
                KEYPAD_3        = 89, 
                KEYPAD_0        = 90, 
                KEYPAD_DECIMAL  = 91, 
                F11             = 95, 
                F12             = 96,
                KEYPAD_ENTER    = 104, 
                F13             = 105, 
                KEYPAD_DIVIDE   = 106, 
                F14             = 107, 
                HOME            = 110, 
                ARROW_UP        = 111, 
                PAGE_UP         = 112, 
                ARROW_LEFT      = 113, 
                ARROW_RIGHT     = 114,
                END             = 115,
                ARROW_DOWN      = 116, 
                PAGE_DOWN       = 117, 
                INSERT          = 118,
                PAUSE           = 127};
            enum class INPUT_TYPE{
                KEYBOARD,
                MOUSE,
                JOYSTICK, 
                MOTION
            };
            InputHandler(InputStream capture, INPUT_TYPE type);
        
    };
}


#endif /* POLARIS__INPUTS_H */