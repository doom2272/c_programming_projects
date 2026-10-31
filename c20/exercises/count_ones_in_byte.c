int count_ones(unsigned char ch) {
  int ones_count = 0;

  for (int i = 7; i >= 0; i--) {
    if (ch & 1)
      ones_count++;

    ch >>= 1;
  }

  return ones_count;
}

// Bit parallel counting (Mandelbrot style bit-mask multiplier)
int count_ones_without_loop(unsigned char ch) {
  ch = (ch & 0x55) + ((ch >> 1) & 0x55);

  ch = (ch & 0x33) + ((ch >> 2) & 0x33);

  ch = (ch & 0x0F) + ((ch >> 4) & 0x0F);

  return ch;
}
