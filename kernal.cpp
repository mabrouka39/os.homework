
extern "C" void afficher() {
    char* video = (char*)0xB8000;
    video[0] = 'X';
    video[1] = 0x0F;
}

extern "C" void main() {
    afficher();
}
