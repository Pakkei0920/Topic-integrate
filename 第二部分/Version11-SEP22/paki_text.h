//V1
static const unsigned char waitrec[] = { //等錄音 112x64
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x0f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x3f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x7f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xff, 0xff, 0x00, 0x00, 0x00, 0x30, 0x04, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xff, 0xff, 0x00, 0x00, 0x00, 0x38, 0x04, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xff, 0xff, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xe1, 0xff, 0xff, 0x1e, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xf1, 0xff, 0xff, 0x1e, 0x00, 0x00, 0x03, 0xe0, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xf1, 0xff, 0xff, 0x1e, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xf1, 0xff, 0xff, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xf1, 0xff, 0xff, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xf1, 0xff, 0xff, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xf1, 0xff, 0xff, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xf1, 0xff, 0xff, 0x1e, 0x00, 0x01, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xf1, 0xff, 0xff, 0x1e, 0x00, 0x01, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xf1, 0xff, 0xff, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xf1, 0xff, 0xff, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xf8, 0xff, 0xfe, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x78, 0xff, 0xfe, 0x3c, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x7c, 0x7f, 0xfc, 0x7c, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x3c, 0x3f, 0xf8, 0x78, 0x00, 0x00, 0x03, 0xe0, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x3e, 0x0f, 0xe0, 0xf8, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x1f, 0x00, 0x01, 0xf0, 0x00, 0x00, 0x1f, 0x04, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x0f, 0xc0, 0x07, 0xe0, 0x00, 0x00, 0x3c, 0x06, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x0f, 0xf0, 0x1f, 0xe0, 0x00, 0x00, 0x30, 0x0e, 0x38, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x1c, 0x38, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x38, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x7f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x38, 0x38, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x1f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x38, 0x38, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x70, 0x38, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x70, 0x38, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x60, 0x38, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x7f, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const unsigned char pmdj[] = { //屏幕待機64x16
    0x00, 0x00, 0x04, 0x40, 0x08, 0x40, 0x11, 0x24, 
    0x3f, 0xf8, 0x7f, 0xfc, 0x08, 0x40, 0x11, 0x24, 
    0x20, 0x08, 0x04, 0x40, 0x10, 0x40, 0x12, 0xaa, 
    0x20, 0x08, 0x1f, 0xf0, 0x23, 0xfc, 0x13, 0xae, 
    0x3f, 0xf8, 0x10, 0x10, 0x48, 0x40, 0xf9, 0x24, 
    0x24, 0x10, 0x1f, 0xf0, 0x08, 0x40, 0x12, 0xaa, 
    0x22, 0x20, 0x10, 0x10, 0x17, 0xfe, 0x33, 0xae, 
    0x2f, 0xf8, 0x1f, 0xf0, 0x30, 0x10, 0x39, 0x24, 
    0x22, 0x20, 0x04, 0x00, 0x50, 0x10, 0x57, 0xfe, 
    0x22, 0x20, 0xff, 0xfe, 0x97, 0xfe, 0x51, 0x10, 
    0x3f, 0xfc, 0x11, 0x10, 0x10, 0x10, 0x91, 0x14, 
    0x22, 0x20, 0x3f, 0xf8, 0x12, 0x10, 0x11, 0x14, 
    0x42, 0x20, 0xd1, 0x16, 0x11, 0x10, 0x12, 0x8a, 
    0x44, 0x20, 0x11, 0x50, 0x11, 0x10, 0x12, 0x4a, 
    0x84, 0x20, 0x11, 0x20, 0x10, 0x50, 0x12, 0x16, 
    0x08, 0x20, 0x01, 0x00, 0x10, 0x20, 0x14, 0x22
};
static const unsigned char png1[] = { //sound+
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x0f, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x1f, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x3f, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xff, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xff, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x03, 0xff, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x07, 0xff, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x1f, 0xff, 0xc0, 0x0f, 0x80, 0x00, 
    0x00, 0x0f, 0xff, 0xff, 0xc0, 0x1f, 0x80, 0x00, 
    0x00, 0x3f, 0xff, 0xff, 0xc0, 0x1f, 0x80, 0x00, 
    0x00, 0x3f, 0xff, 0xff, 0xc0, 0x1f, 0x80, 0x00, 
    0x00, 0x7f, 0xff, 0xff, 0xc0, 0x1f, 0x80, 0x00, 
    0x00, 0x7f, 0xff, 0xff, 0xc3, 0xff, 0xfe, 0x00, 
    0x00, 0x7f, 0xff, 0xff, 0xc3, 0xff, 0xfe, 0x00, 
    0x00, 0x7f, 0xff, 0xff, 0xc3, 0xff, 0xfe, 0x00, 
    0x00, 0x7f, 0xff, 0xff, 0xc3, 0xff, 0xfe, 0x00, 
    0x00, 0x7f, 0xff, 0xff, 0xc3, 0xff, 0xfe, 0x00, 
    0x00, 0x7f, 0xff, 0xff, 0xc3, 0xff, 0xfe, 0x00, 
    0x00, 0x7f, 0xff, 0xff, 0xc0, 0x1f, 0x80, 0x00, 
    0x00, 0x3f, 0xff, 0xff, 0xc0, 0x1f, 0x80, 0x00, 
    0x00, 0x3f, 0xff, 0xff, 0xc0, 0x1f, 0x80, 0x00, 
    0x00, 0x0f, 0xff, 0xff, 0xc0, 0x1f, 0x80, 0x00, 
    0x00, 0x00, 0x1f, 0xff, 0xc0, 0x0f, 0x80, 0x00, 
    0x00, 0x00, 0x0f, 0xff, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x03, 0xff, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xff, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xff, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x3f, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x1f, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x0f, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const unsigned char png2[] = {//sound--
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x0f, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x1f, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x3f, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x7f, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xff, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x03, 0xff, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x07, 0xff, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x0f, 0xff, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x1f, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x3f, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x3f, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x7f, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x7f, 0xff, 0xff, 0xc3, 0xff, 0xfe, 0x00, 
    0x00, 0x7f, 0xff, 0xff, 0xc3, 0xff, 0xfe, 0x00, 
    0x00, 0x7f, 0xff, 0xff, 0xc3, 0xff, 0xfe, 0x00, 
    0x00, 0x7f, 0xff, 0xff, 0xc3, 0xff, 0xfe, 0x00, 
    0x00, 0x7f, 0xff, 0xff, 0xc3, 0xff, 0xfe, 0x00, 
    0x00, 0x7f, 0xff, 0xff, 0xc3, 0xff, 0xfe, 0x00, 
    0x00, 0x7f, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x3f, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x3f, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x1f, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x0f, 0xff, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x07, 0xff, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x03, 0xff, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xff, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x7f, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x3f, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x1f, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x0f, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
static const unsigned char dybk[] = { //第一板塊64x16
    0x20, 0x40, 0x00, 0x00, 0x10, 0x08, 0x20, 0x20, 
    0x3f, 0x7e, 0x00, 0x00, 0x10, 0x1c, 0x20, 0x40, 
    0x48, 0x90, 0x00, 0x00, 0x11, 0xe0, 0x23, 0xfc, 
    0x85, 0x08, 0x00, 0x00, 0x11, 0x00, 0x22, 0x24, 
    0x3f, 0xf8, 0x00, 0x00, 0xfd, 0x00, 0x22, 0x24, 
    0x01, 0x08, 0x00, 0x00, 0x11, 0xfc, 0xfb, 0xfc, 
    0x01, 0x08, 0x00, 0x00, 0x31, 0x44, 0x22, 0x24, 
    0x3f, 0xf8, 0xff, 0xfe, 0x39, 0x44, 0x22, 0x44, 
    0x21, 0x00, 0x00, 0x00, 0x55, 0x44, 0x23, 0xfc, 
    0x21, 0x00, 0x00, 0x00, 0x55, 0x28, 0x20, 0x40, 
    0x3f, 0xfc, 0x00, 0x00, 0x91, 0x28, 0x20, 0xa8, 
    0x03, 0x04, 0x00, 0x00, 0x11, 0x10, 0x38, 0xb4, 
    0x05, 0x04, 0x00, 0x00, 0x11, 0x10, 0xe1, 0x3c, 
    0x19, 0x28, 0x00, 0x00, 0x12, 0x28, 0x41, 0x22, 
    0xe1, 0x10, 0x00, 0x00, 0x12, 0x44, 0x02, 0x22, 
    0x01, 0x00, 0x00, 0x00, 0x14, 0x82, 0x04, 0x1e
};

static const unsigned char dsbk[] = {//第三板塊64x16
    0x20, 0x40, 0x00, 0x00, 0x10, 0x08, 0x20, 0x20, 
    0x3f, 0x7e, 0x00, 0x00, 0x10, 0x1c, 0x20, 0x40, 
    0x48, 0x90, 0x7f, 0xfc, 0x11, 0xe0, 0x23, 0xfc, 
    0x85, 0x08, 0x00, 0x00, 0x11, 0x00, 0x22, 0x24, 
    0x3f, 0xf8, 0x00, 0x00, 0xfd, 0x00, 0x22, 0x24, 
    0x01, 0x08, 0x00, 0x00, 0x11, 0xfc, 0xfb, 0xfc, 
    0x01, 0x08, 0x00, 0x00, 0x31, 0x44, 0x22, 0x24, 
    0x3f, 0xf8, 0x3f, 0xf8, 0x39, 0x44, 0x22, 0x44, 
    0x21, 0x00, 0x00, 0x00, 0x55, 0x44, 0x23, 0xfc, 
    0x21, 0x00, 0x00, 0x00, 0x55, 0x28, 0x20, 0x40, 
    0x3f, 0xfc, 0x00, 0x00, 0x91, 0x28, 0x20, 0xa8, 
    0x03, 0x04, 0x00, 0x00, 0x11, 0x10, 0x38, 0xb4, 
    0x05, 0x04, 0x00, 0x00, 0x11, 0x10, 0xe1, 0x3c, 
    0x19, 0x28, 0xff, 0xfe, 0x12, 0x28, 0x41, 0x22, 
    0xe1, 0x10, 0x00, 0x00, 0x12, 0x44, 0x02, 0x22, 
    0x01, 0x00, 0x00, 0x00, 0x14, 0x82, 0x04, 0x1e
};
static const unsigned char wlljz[] = { //網絡連接中
    0x10, 0x00, 0x10, 0x40, 0x00, 0x40, 0x10, 0x80, 0x01, 0x00, 
    0x13, 0xfe, 0x10, 0x40, 0x40, 0x40, 0x10, 0x40, 0x01, 0x00, 
    0x22, 0x02, 0x20, 0x78, 0x2f, 0xfe, 0x13, 0xfc, 0x01, 0x00, 
    0x2a, 0x8a, 0x24, 0x88, 0x20, 0x40, 0x10, 0x00, 0x01, 0x00, 
    0x4a, 0x52, 0x45, 0x50, 0x07, 0xfc, 0xfd, 0x08, 0x3f, 0xf8, 
    0xf3, 0xfe, 0xf8, 0x20, 0x04, 0x44, 0x10, 0x90, 0x21, 0x08, 
    0x12, 0x42, 0x10, 0x50, 0xe7, 0xfc, 0x17, 0xfe, 0x21, 0x08, 
    0x22, 0x22, 0x20, 0x88, 0x24, 0x44, 0x10, 0x40, 0x21, 0x08, 
    0x4b, 0xfe, 0x49, 0x06, 0x27, 0xfc, 0x18, 0x40, 0x21, 0x08, 
    0xfa, 0x82, 0xfc, 0xf8, 0x20, 0x40, 0x37, 0xfe, 0x21, 0x08, 
    0x0a, 0x82, 0x04, 0x88, 0x2f, 0xfe, 0xd0, 0x88, 0x3f, 0xf8, 
    0x02, 0x82, 0x00, 0x88, 0x20, 0x40, 0x11, 0x08, 0x21, 0x08, 
    0xaa, 0xfa, 0x54, 0x88, 0x20, 0x40, 0x10, 0x90, 0x01, 0x00, 
    0xaa, 0x02, 0x54, 0x88, 0x50, 0x40, 0x10, 0x60, 0x01, 0x00, 
    0x82, 0x0a, 0x80, 0xf8, 0x8f, 0xfe, 0x51, 0x98, 0x01, 0x00, 
    0x02, 0x04, 0x00, 0x88, 0x00, 0x00, 0x26, 0x04, 0x01, 0x00
};
static const unsigned char wlljcg[] = {//網絡連接成功
    0x10, 0x00, 0x10, 0x40, 0x00, 0x40, 0x10, 0x80, 0x00, 0x50, 0x00, 0x40, 
    0x13, 0xfe, 0x10, 0x40, 0x40, 0x40, 0x10, 0x40, 0x00, 0x48, 0x00, 0x40, 
    0x22, 0x02, 0x20, 0x78, 0x2f, 0xfe, 0x13, 0xfc, 0x00, 0x40, 0x00, 0x40, 
    0x2a, 0x8a, 0x24, 0x88, 0x20, 0x40, 0x10, 0x00, 0x3f, 0xfe, 0xfe, 0x40, 
    0x4a, 0x52, 0x45, 0x50, 0x07, 0xfc, 0xfd, 0x08, 0x20, 0x40, 0x11, 0xfc, 
    0xf3, 0xfe, 0xf8, 0x20, 0x04, 0x44, 0x10, 0x90, 0x20, 0x40, 0x10, 0x44, 
    0x12, 0x42, 0x10, 0x50, 0xe7, 0xfc, 0x17, 0xfe, 0x20, 0x44, 0x10, 0x44, 
    0x22, 0x22, 0x20, 0x88, 0x24, 0x44, 0x10, 0x40, 0x3e, 0x44, 0x10, 0x44, 
    0x4b, 0xfe, 0x49, 0x06, 0x27, 0xfc, 0x18, 0x40, 0x22, 0x44, 0x10, 0x44, 
    0xfa, 0x82, 0xfc, 0xf8, 0x20, 0x40, 0x37, 0xfe, 0x22, 0x28, 0x10, 0x84, 
    0x0a, 0x82, 0x04, 0x88, 0x2f, 0xfe, 0xd0, 0x88, 0x22, 0x28, 0x10, 0x84, 
    0x02, 0x82, 0x00, 0x88, 0x20, 0x40, 0x11, 0x08, 0x22, 0x12, 0x1e, 0x84, 
    0xaa, 0xfa, 0x54, 0x88, 0x20, 0x40, 0x10, 0x90, 0x2a, 0x32, 0xf1, 0x04, 
    0xaa, 0x02, 0x54, 0x88, 0x50, 0x40, 0x10, 0x60, 0x44, 0x4a, 0x41, 0x04, 
    0x82, 0x0a, 0x80, 0xf8, 0x8f, 0xfe, 0x51, 0x98, 0x40, 0x86, 0x02, 0x28, 
    0x02, 0x04, 0x00, 0x88, 0x00, 0x00, 0x26, 0x04, 0x81, 0x02, 0x04, 0x10
};
static const unsigned char bq[] = { //版權
    0x00, 0x00, 
    0x00, 0x00, 
    0x00, 0x00, 
    0x18, 0x00, 
    0x66, 0x00, 
    0xbd, 0x00, 
    0xc1, 0x00, 
    0xc1, 0x00, 
    0xc1, 0x00, 
    0xbd, 0x00, 
    0x46, 0x00, 
    0x38, 0x00, 
    0x00, 0x00, 
    0x00, 0x00, 
    0x00, 0x00, 
    0x00, 0x00
};
static const unsigned char ying[] = { //應
    0x01, 0x00, 
    0x00, 0x80, 
    0x3f, 0xfe, 
    0x22, 0x48, 
    0x24, 0xfe, 
    0x2d, 0x90, 
    0x34, 0xfc, 
    0x24, 0x90, 
    0x24, 0xfc, 
    0x24, 0x90, 
    0x24, 0xfe, 
    0x24, 0x80, 
    0x42, 0x44, 
    0x52, 0x4a, 
    0x92, 0x0a, 
    0x21, 0xf8
};
static const unsigned char yong[] = { //用
    0x00, 0x00, 
    0x3f, 0xf8, 
    0x21, 0x08, 
    0x21, 0x08, 
    0x21, 0x08, 
    0x3f, 0xf8, 
    0x21, 0x08, 
    0x21, 0x08, 
    0x21, 0x08, 
    0x3f, 0xf8, 
    0x21, 0x08, 
    0x21, 0x08, 
    0x21, 0x08, 
    0x41, 0x08, 
    0x41, 0x28, 
    0x80, 0x10
};

static const unsigned char kai[] = { //開
    0x00, 0x00, 
    0x7c, 0xf8, 
    0x44, 0x88, 
    0x7c, 0xf8, 
    0x44, 0x88, 
    0x7c, 0xf8, 
    0x40, 0x08, 
    0x4f, 0xc8, 
    0x44, 0x88, 
    0x44, 0x88, 
    0x5f, 0xe8, 
    0x44, 0x88, 
    0x44, 0x88, 
    0x48, 0x88, 
    0x50, 0xa8, 
    0x40, 0x10
};

static const unsigned char fa[] = { //發
    0x00, 0x90, 
    0x7e, 0xa0, 
    0x04, 0x44, 
    0x28, 0x28, 
    0x10, 0x10, 
    0x3c, 0xf8, 
    0xc4, 0x96, 
    0x04, 0x90, 
    0x3d, 0x0c, 
    0x20, 0x00, 
    0x41, 0xf8, 
    0x7c, 0x08, 
    0x04, 0xd0, 
    0x04, 0x20, 
    0x28, 0x50, 
    0x11, 0x88
};

static const unsigned char xian2[] = {//現
    0x00, 0x00, 
    0x01, 0xfc, 
    0xfd, 0x04, 
    0x11, 0x04, 
    0x11, 0xfc, 
    0x11, 0x04, 
    0x11, 0x04, 
    0x7d, 0xfc, 
    0x11, 0x04, 
    0x11, 0x04, 
    0x11, 0xfc, 
    0x10, 0x50, 
    0x1c, 0x90, 
    0xe0, 0x92, 
    0x41, 0x12, 
    0x02, 0x0e
};
static const unsigned char zai[] = {//在
    0x02, 0x00, 
    0x02, 0x00, 
    0x04, 0x00, 
    0xff, 0xfe, 
    0x08, 0x00, 
    0x08, 0x40, 
    0x10, 0x40, 
    0x30, 0x40, 
    0x57, 0xfc, 
    0x90, 0x40, 
    0x10, 0x40, 
    0x10, 0x40, 
    0x10, 0x40, 
    0x10, 0x40, 
    0x1f, 0xfe, 
    0x10, 0x00
};


static const unsigned char da[] = {//大
    0x01, 0x00, 
    0x01, 0x00, 
    0x01, 0x00, 
    0x01, 0x00, 
    0x01, 0x00, 
    0xff, 0xfe, 
    0x01, 0x00, 
    0x01, 0x00, 
    0x02, 0x80, 
    0x02, 0x80, 
    0x04, 0x40, 
    0x04, 0x40, 
    0x08, 0x20, 
    0x10, 0x10, 
    0x20, 0x08, 
    0xc0, 0x06
};
static const unsigned char xiao[] = {//小
    0x01, 0x00, 
    0x01, 0x00, 
    0x01, 0x00, 
    0x01, 0x00, 
    0x01, 0x00, 
    0x11, 0x10, 
    0x11, 0x08, 
    0x11, 0x04, 
    0x21, 0x04, 
    0x21, 0x02, 
    0x41, 0x02, 
    0x81, 0x02, 
    0x01, 0x00, 
    0x01, 0x00, 
    0x05, 0x00, 
    0x02, 0x00
};


static const unsigned char sheng [] = {//聲
    0x08, 0x00, 
    0x7f, 0x78, 
    0x08, 0x48, 
    0x3e, 0x48, 
    0x00, 0x86, 
    0x3e, 0x78, 
    0x2a, 0x48, 
    0x3e, 0x30, 
    0x40, 0x48, 
    0xff, 0xfe, 
    0x08, 0x20, 
    0x0f, 0xe0, 
    0x08, 0x3e, 
    0xff, 0xe0, 
    0x00, 0x20, 
    0x00, 0x20
};
static const unsigned char yin[] = {//音
    0x02, 0x00, 
    0x01, 0x00, 
    0x3f, 0xf8, 
    0x00, 0x00, 
    0x08, 0x20, 
    0x04, 0x40, 
    0xff, 0xfe, 
    0x00, 0x00, 
    0x1f, 0xf0, 
    0x10, 0x10, 
    0x10, 0x10, 
    0x1f, 0xf0, 
    0x10, 0x10, 
    0x10, 0x10, 
    0x1f, 0xf0, 
    0x10, 0x10
};


static const unsigned char mu[] = {//目
    0x00, 0x00, 
    0x3f, 0xf8, 
    0x20, 0x08, 
    0x20, 0x08, 
    0x20, 0x08, 
    0x3f, 0xf8, 
    0x20, 0x08, 
    0x20, 0x08, 
    0x20, 0x08, 
    0x3f, 0xf8, 
    0x20, 0x08, 
    0x20, 0x08, 
    0x20, 0x08, 
    0x20, 0x08, 
    0x3f, 0xf8, 
    0x20, 0x08
};
static const unsigned char qian[] = {//前
    0x10, 0x10, 
    0x08, 0x10, 
    0x08, 0x20, 
    0xff, 0xfe, 
    0x00, 0x00, 
    0x3e, 0x08, 
    0x22, 0x48, 
    0x22, 0x48, 
    0x3e, 0x48, 
    0x22, 0x48, 
    0x22, 0x48, 
    0x3e, 0x48, 
    0x22, 0x08, 
    0x22, 0x08, 
    0x2a, 0x28, 
    0x24, 0x10
};


static const unsigned char ban[] = {//版
    0x08, 0x08, 
    0x48, 0x1c, 
    0x49, 0xe0, 
    0x49, 0x00, 
    0x49, 0x00, 
    0x7d, 0xfc, 
    0x41, 0x44, 
    0x41, 0x44, 
    0x79, 0x44, 
    0x49, 0x28, 
    0x49, 0x28, 
    0x49, 0x10, 
    0x49, 0x10, 
    0x4a, 0x28, 
    0x4a, 0x44, 
    0x8c, 0x82
};
static const unsigned char quan[] = {//權
    0x10, 0x88, 
    0x13, 0xfe, 
    0x10, 0x88, 
    0x13, 0xde, 
    0xfe, 0x52, 
    0x13, 0xde, 
    0x30, 0xa0, 
    0x38, 0x90, 
    0x55, 0xfe, 
    0x51, 0x20, 
    0x93, 0xfc, 
    0x15, 0x20, 
    0x11, 0xfc, 
    0x11, 0x20, 
    0x11, 0xfe, 
    0x11, 0x00
};

static const unsigned char shou[] = {//收
    0x08, 0x40, 
    0x08, 0x40, 
    0x48, 0x40, 
    0x48, 0x80, 
    0x48, 0xfe, 
    0x49, 0x08, 
    0x4a, 0x88, 
    0x48, 0x88, 
    0x48, 0x88, 
    0x58, 0x50, 
    0x68, 0x50, 
    0x48, 0x20, 
    0x08, 0x50, 
    0x08, 0x88, 
    0x09, 0x04, 
    0x0a, 0x02
};


static const unsigned char wang[] = {//網
    0x10, 0x00, 
    0x13, 0xfe, 
    0x22, 0x02, 
    0x2a, 0x8a, 
    0x4a, 0x52, 
    0xf3, 0xfe, 
    0x12, 0x42, 
    0x22, 0x22, 
    0x4b, 0xfe, 
    0xfa, 0x82, 
    0x0a, 0x82, 
    0x02, 0x82, 
    0xaa, 0xfa, 
    0xaa, 0x02, 
    0x82, 0x0a, 
    0x02, 0x04
};
static const unsigned char lu2[] = {//路
    0x00, 0x40, 
    0x7c, 0x40, 
    0x44, 0x78, 
    0x44, 0x88, 
    0x45, 0x50, 
    0x7c, 0x20, 
    0x10, 0x50, 
    0x10, 0x88, 
    0x11, 0x06, 
    0x5c, 0xf8, 
    0x50, 0x88, 
    0x50, 0x88, 
    0x50, 0x88, 
    0x5c, 0x88, 
    0xe0, 0xf8, 
    0x00, 0x88
};


static const unsigned char lian[] = {//連
    0x00, 0x40, 
    0x40, 0x40, 
    0x2f, 0xfe, 
    0x20, 0x40, 
    0x07, 0xfc, 
    0x04, 0x44, 
    0xe7, 0xfc, 
    0x24, 0x44, 
    0x27, 0xfc, 
    0x20, 0x40, 
    0x2f, 0xfe, 
    0x20, 0x40, 
    0x20, 0x40, 
    0x50, 0x40, 
    0x8f, 0xfe, 
    0x00, 0x00
};
static const unsigned char jie[] = {//接
    0x10, 0x80, 
    0x10, 0x40, 
    0x13, 0xfc, 
    0x10, 0x00, 
    0xfd, 0x08, 
    0x10, 0x90, 
    0x17, 0xfe, 
    0x10, 0x40, 
    0x18, 0x40, 
    0x37, 0xfe, 
    0xd0, 0x88, 
    0x11, 0x08, 
    0x10, 0x90, 
    0x10, 0x60, 
    0x51, 0x98, 
    0x26, 0x04
};


static const unsigned char cheng[] = {//成
    0x00, 0x50, 
    0x00, 0x48, 
    0x00, 0x40, 
    0x3f, 0xfe, 
    0x20, 0x40, 
    0x20, 0x40, 
    0x20, 0x44, 
    0x3e, 0x44, 
    0x22, 0x44, 
    0x22, 0x28, 
    0x22, 0x28, 
    0x22, 0x12, 
    0x2a, 0x32, 
    0x44, 0x4a, 
    0x40, 0x86, 
    0x81, 0x02
};
static const unsigned char gong[] = {//功
    0x00, 0x40, 
    0x00, 0x40, 
    0x00, 0x40, 
    0xfe, 0x40, 
    0x11, 0xfc, 
    0x10, 0x44, 
    0x10, 0x44, 
    0x10, 0x44, 
    0x10, 0x44, 
    0x10, 0x84, 
    0x10, 0x84, 
    0x1e, 0x84, 
    0xf1, 0x04, 
    0x41, 0x04, 
    0x02, 0x28, 
    0x04, 0x10
};


static const unsigned char zhong[] = {//中
    0x01, 0x00, 
    0x01, 0x00, 
    0x01, 0x00, 
    0x01, 0x00, 
    0x3f, 0xf8, 
    0x21, 0x08, 
    0x21, 0x08, 
    0x21, 0x08, 
    0x21, 0x08, 
    0x21, 0x08, 
    0x3f, 0xf8, 
    0x21, 0x08, 
    0x01, 0x00, 
    0x01, 0x00, 
    0x01, 0x00, 
    0x01, 0x00
};
static const unsigned char zheng[] = {//正
    0x00, 0x00, 
    0x7f, 0xfc, 
    0x01, 0x00, 
    0x01, 0x00, 
    0x01, 0x00, 
    0x01, 0x00, 
    0x11, 0x00, 
    0x11, 0xf8, 
    0x11, 0x00, 
    0x11, 0x00, 
    0x11, 0x00, 
    0x11, 0x00, 
    0x11, 0x00, 
    0x11, 0x00, 
    0xff, 0xfe, 
    0x00, 0x00
};


static const unsigned char lu[] = {//錄
    0x10, 0x80, 
    0x10, 0xf8, 
    0x28, 0x88, 
    0x25, 0x08, 
    0x41, 0xf0, 
    0xb8, 0x10, 
    0x10, 0x10, 
    0x13, 0xfe, 
    0xfc, 0x20, 
    0x12, 0x22, 
    0x95, 0x74, 
    0x58, 0xa8, 
    0x51, 0x24, 
    0x1e, 0x22, 
    0xe0, 0xa0, 
    0x40, 0x40
};

static const unsigned char wei[] = {//危
    0x04, 0x00, 
    0x04, 0x00, 
    0x0f, 0xf0, 
    0x10, 0x10, 
    0x20, 0x20, 
    0x5f, 0xfc, 
    0x10, 0x00, 
    0x13, 0xf0, 
    0x12, 0x10, 
    0x12, 0x10, 
    0x12, 0x50, 
    0x12, 0x20, 
    0x22, 0x04, 
    0x22, 0x04, 
    0x41, 0xfc, 
    0x80, 0x00
};
static const unsigned char xian1[] = {//險
    0x00, 0x20, 
    0x7c, 0x20, 
    0x44, 0x50, 
    0x48, 0x88, 
    0x49, 0x04, 
    0x52, 0xfa, 
    0x48, 0x00, 
    0x48, 0x00, 
    0x45, 0xdc, 
    0x45, 0x54, 
    0x45, 0x54, 
    0x69, 0xdc, 
    0x50, 0x88, 
    0x40, 0x88, 
    0x41, 0x54, 
    0x42, 0x22
};

static const unsigned char song[] = {//送
    0x02, 0x08, 
    0x21, 0x08, 
    0x11, 0x10, 
    0x17, 0xfc, 
    0x00, 0x40, 
    0x00, 0x40, 
    0xf0, 0x40, 
    0x17, 0xfe, 
    0x10, 0x40, 
    0x10, 0xa0, 
    0x10, 0x90, 
    0x11, 0x08, 
    0x12, 0x08, 
    0x28, 0x00, 
    0x47, 0xfe, 
    0x00, 0x00
};


static const unsigned char jia[] = {//加
    0x10, 0x00, 
    0x10, 0x00, 
    0x10, 0x00, 
    0x10, 0x7c, 
    0xfe, 0x44, 
    0x12, 0x44, 
    0x12, 0x44, 
    0x12, 0x44, 
    0x12, 0x44, 
    0x12, 0x44, 
    0x12, 0x44, 
    0x12, 0x44, 
    0x22, 0x44, 
    0x22, 0x7c, 
    0x4a, 0x44, 
    0x84, 0x00
};
static const unsigned char jian2[] = {//減
    0x00, 0x14, 
    0x20, 0x12, 
    0x10, 0x10, 
    0x17, 0xfe, 
    0x84, 0x10, 
    0x44, 0x10, 
    0x45, 0xd0, 
    0x14, 0x12, 
    0x14, 0x12, 
    0x25, 0xd4, 
    0xe5, 0x54, 
    0x25, 0x48, 
    0x25, 0xda, 
    0x24, 0x2a, 
    0x28, 0x46, 
    0x10, 0x82
};


static const unsigned char wen[] = {//溫
    0x00, 0x00, 
    0x23, 0xf8, 
    0x12, 0x48, 
    0x12, 0xa8, 
    0x83, 0x18, 
    0x42, 0x08, 
    0x43, 0xf8, 
    0x10, 0x00, 
    0x10, 0x00, 
    0x27, 0xfc, 
    0xe4, 0xa4, 
    0x24, 0xa4, 
    0x24, 0xa4, 
    0x24, 0xa4, 
    0x2f, 0xfe, 
    0x00, 0x00
};

static const unsigned char shi1[] = {//濕
    0x00, 0x00, 
    0x27, 0xfc, 
    0x14, 0x04, 
    0x17, 0xfc, 
    0x84, 0x04, 
    0x47, 0xfc, 
    0x42, 0x10, 
    0x14, 0xa4, 
    0x17, 0x38, 
    0x22, 0x10, 
    0xe4, 0xa4, 
    0x27, 0xbc, 
    0x20, 0x00, 
    0x25, 0x48, 
    0x24, 0xa4, 
    0x08, 0xa4
};
static const unsigned char du1[] = {//度
    0x01, 0x00, 
    0x00, 0x80, 
    0x3f, 0xfe, 
    0x22, 0x20, 
    0x22, 0x20, 
    0x3f, 0xfc, 
    0x22, 0x20, 
    0x22, 0x20, 
    0x23, 0xe0, 
    0x20, 0x00, 
    0x2f, 0xf0, 
    0x24, 0x10, 
    0x42, 0x20, 
    0x41, 0xc0, 
    0x86, 0x30, 
    0x38, 0x0e
};


static const unsigned char kong[] = {//空
    0x02, 0x00, 
    0x01, 0x00, 
    0x7f, 0xfe, 
    0x40, 0x02, 
    0x88, 0x24, 
    0x10, 0x10, 
    0x20, 0x08, 
    0x00, 0x00, 
    0x1f, 0xf0, 
    0x01, 0x00, 
    0x01, 0x00, 
    0x01, 0x00, 
    0x01, 0x00, 
    0x01, 0x00, 
    0x7f, 0xfc, 
    0x00, 0x00
};
static const unsigned char qi2[] = {//氣
    0x10, 0x00, 
    0x10, 0x00, 
    0x3f, 0xfc, 
    0x20, 0x00, 
    0x4f, 0xf0, 
    0x80, 0x00, 
    0x3f, 0xf0, 
    0x04, 0x10, 
    0x24, 0x90, 
    0x15, 0x10, 
    0x7f, 0xd0, 
    0x0e, 0x10, 
    0x15, 0x0a, 
    0x24, 0x8a, 
    0x44, 0x46, 
    0x04, 0x02
};


static const unsigned char zhuang[] = {//狀
    0x04, 0x20, 
    0x24, 0x28, 
    0x24, 0x24, 
    0x24, 0x24, 
    0x24, 0x20, 
    0x3d, 0xfe, 
    0x04, 0x20, 
    0x04, 0x20, 
    0xfc, 0x20, 
    0x24, 0x50, 
    0x24, 0x50, 
    0x24, 0x50, 
    0x24, 0x88, 
    0x44, 0x88, 
    0x45, 0x04, 
    0x86, 0x02
};
static const unsigned char kuang[] = {//況
    0x00, 0x00, 
    0x27, 0xf8, 
    0x14, 0x08, 
    0x14, 0x08, 
    0x84, 0x08, 
    0x44, 0x08, 
    0x47, 0xf8, 
    0x11, 0x20, 
    0x11, 0x20, 
    0x21, 0x20, 
    0xe1, 0x20, 
    0x22, 0x20, 
    0x22, 0x22, 
    0x24, 0x22, 
    0x28, 0x1e, 
    0x10, 0x00
};


static const unsigned char shu[] = {//樹
    0x21, 0x04, 
    0x21, 0x04, 
    0x2f, 0xe4, 
    0x21, 0x04, 
    0xf9, 0x3e, 
    0x27, 0xc4, 
    0x20, 0x04, 
    0x77, 0xe4, 
    0x6c, 0x54, 
    0xa4, 0x54, 
    0xa7, 0xc4, 
    0x24, 0x44, 
    0x22, 0x84, 
    0x20, 0xe4, 
    0x2f, 0x14, 
    0x24, 0x08
};
static const unsigned char de[] = {//德
    0x10, 0x40, 
    0x10, 0x40, 
    0x2f, 0xfe, 
    0x40, 0x40, 
    0x97, 0xfc, 
    0x14, 0xa4, 
    0x24, 0xa4, 
    0x67, 0xfc, 
    0xa0, 0x00, 
    0x2f, 0xfe, 
    0x20, 0x40, 
    0x20, 0x24, 
    0x25, 0x22, 
    0x25, 0x0a, 
    0x29, 0x08, 
    0x20, 0xf8
};


static const unsigned char ke[] = {//科
    0x08, 0x10, 
    0x1d, 0x10, 
    0xf0, 0x90, 
    0x10, 0x90, 
    0x10, 0x10, 
    0xfd, 0x10, 
    0x10, 0x90, 
    0x38, 0x90, 
    0x34, 0x10, 
    0x50, 0x1e, 
    0x53, 0xf0, 
    0x90, 0x10, 
    0x10, 0x10, 
    0x10, 0x10, 
    0x10, 0x10, 
    0x10, 0x10
};
static const unsigned char ji[] = {//技
    0x10, 0x20, 
    0x10, 0x20, 
    0x10, 0x20, 
    0x13, 0xfe, 
    0xfc, 0x20, 
    0x10, 0x20, 
    0x10, 0x20, 
    0x15, 0xfc, 
    0x18, 0x84, 
    0x30, 0x88, 
    0xd0, 0x48, 
    0x10, 0x50, 
    0x10, 0x20, 
    0x10, 0x50, 
    0x51, 0x88, 
    0x26, 0x06
};


static const unsigned char xue[] = {//學
    0x0a, 0x80, 
    0x31, 0x38, 
    0x22, 0x88, 
    0x38, 0x38, 
    0x22, 0x88, 
    0x39, 0x38, 
    0x22, 0x88, 
    0x7f, 0xfe, 
    0x40, 0x02, 
    0xbf, 0xe4, 
    0x00, 0x80, 
    0x01, 0x00, 
    0xff, 0xfe, 
    0x01, 0x00, 
    0x05, 0x00, 
    0x02, 0x00
};
static const unsigned char qi1[] = {//啟
    0x08, 0x20, 
    0x04, 0x20, 
    0x3f, 0x20, 
    0x21, 0x3e, 
    0x21, 0x44, 
    0x21, 0x44, 
    0x3f, 0x44, 
    0x20, 0xa4, 
    0x20, 0x28, 
    0x3f, 0x28, 
    0x31, 0x10, 
    0x51, 0x10, 
    0x51, 0x28, 
    0x9f, 0x28, 
    0x11, 0x44, 
    0x00, 0x82
};


static const unsigned char dong[] = {//動
    0x0f, 0x20, 
    0x78, 0x20, 
    0x08, 0x20, 
    0xff, 0xa0, 
    0x08, 0x7c, 
    0x7f, 0x24, 
    0x49, 0x24, 
    0x7f, 0x24, 
    0x49, 0x24, 
    0x7f, 0x24, 
    0x08, 0x24, 
    0x7f, 0x24, 
    0x08, 0x44, 
    0x0f, 0xc4, 
    0xf8, 0x94, 
    0x41, 0x08
};
static const unsigned char shi2 [] = {//時
    0x00, 0x20, 
    0x00, 0x20, 
    0x7c, 0x20, 
    0x45, 0xfc, 
    0x44, 0x20, 
    0x44, 0x20, 
    0x47, 0xfe, 
    0x7c, 0x08, 
    0x44, 0x08, 
    0x45, 0xfe, 
    0x44, 0x08, 
    0x44, 0x88, 
    0x7c, 0x48, 
    0x44, 0x08, 
    0x00, 0x28, 
    0x00, 0x10
};


static const unsigned char jian1[] = {//間
    0x00, 0x00, 
    0x7c, 0xf8, 
    0x44, 0x88, 
    0x7c, 0xf8, 
    0x44, 0x88, 
    0x7c, 0xf8, 
    0x40, 0x08, 
    0x4f, 0xc8, 
    0x48, 0x48, 
    0x4f, 0xc8, 
    0x48, 0x48, 
    0x4f, 0xc8, 
    0x48, 0x48, 
    0x40, 0x08, 
    0x40, 0x28, 
    0x40, 0x10
};
static const unsigned char shi3[] = {//失
    0x01, 0x00, 
    0x11, 0x00, 
    0x11, 0x00, 
    0x11, 0x00, 
    0x3f, 0xf8, 
    0x21, 0x00, 
    0x41, 0x00, 
    0x01, 0x00, 
    0xff, 0xfe, 
    0x02, 0x80, 
    0x04, 0x40, 
    0x04, 0x40, 
    0x08, 0x20, 
    0x10, 0x10, 
    0x20, 0x08, 
    0xc0, 0x06
};


static const unsigned char bai[] = {//敗
    0x00, 0x40, 
    0x7c, 0x40, 
    0x44, 0x80, 
    0x44, 0xfe, 
    0x7d, 0x08, 
    0x45, 0x08, 
    0x46, 0x88, 
    0x7c, 0x88, 
    0x44, 0x88, 
    0x44, 0x50, 
    0x7c, 0x50, 
    0x00, 0x20, 
    0x28, 0x50, 
    0x24, 0x88, 
    0x45, 0x04, 
    0x82, 0x02
};
