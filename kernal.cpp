xtern "C" void main () {
2 // Pointer to Video Memory
3 char * video_memory = ( char *) 0 xb8000 ;
4
5 // Print ’X’ in the top - left corner
6 video_memory [0] = ’X’;
7 video_memory [1] = 0 x0f ; // White on Black
