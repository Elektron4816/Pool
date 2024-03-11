#include "state.h"

#include <stdio.h>

struct Data get_by_id(FILE *stream, int id) {
    struct Data data;
    fseek(stream, id * sizeof(struct Data), SEEK_SET);
    fread(&data, sizeof(struct Data), 1, stream);
    return data;
}

void set_by_id(FILE *stream, int id, struct Data *data) {
    fseek(stream, id * sizeof(struct Data), SEEK_SET);
    fwrite(data, sizeof(struct Data), 1, stream);
}