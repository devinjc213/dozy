#define TILE_SIZE 16
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) < (b) ? (b) : (a))

typedef struct {
  float offset_x, offset_y;
  float scale;
} ZoomState;
