extern "C" {

unsigned short VideoEntry(char character, unsigned char color) {
    return static_cast<unsigned short>(character) | (color << 8);
}

unsigned short* video = (unsigned short*)0xB8000;
unsigned char current_line = 0;
unsigned char current_pos = 0;
const unsigned char VIDEO_WIDTH = 80;
const unsigned char VIDEO_HEIGHT = 25;

void PrintCharacter(char character, unsigned char color) {
    if(character == '\n') {
        current_line++;
        current_pos = 0;
    } else {
        video[current_line * VIDEO_WIDTH + current_pos] = VideoEntry(character, color);
        current_pos++;
        if(current_pos == VIDEO_WIDTH) {
            current_pos = 0;
            current_line++;
            if(current_line == VIDEO_HEIGHT) current_line = 0;
        }
    }
}

void main() {
    PrintCharacter('X', 0x0F);
}

}
