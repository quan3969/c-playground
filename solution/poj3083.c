/**
 * 3083. Children of the Candy Corn
 * http://poj.org/problem?id=3083
 * 
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int step;
} Pos;

typedef struct {
    Pos** pos;
    int front;
    int back;
    int capa;
} Track;

int choice[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

Track* create(int capa) {
    Track* t = malloc(sizeof(Track));
    t->back = t->front = 0;
    t->capa = capa;
    t->pos = malloc(sizeof(Pos*) * t->capa);
    return t;
}

int is_empty(Track* t) {
    return t->back == t->front;
}

void push_back(Track* t, Pos* p) {
    if (t->back == t->capa) {
        t->capa *= 2;
        t->pos = realloc(t->pos, sizeof(Pos*) * t->capa);
    }
    t->pos[t->back++] = p;
}

Pos* pop_front(Track* t) {
    if (is_empty(t)) {
        return NULL;
    }
    return t->pos[t->front++]; 
}

int dfs_left(char** maze, int width, int height, Pos sta, Pos end) {
    int cnt = 1;
    int dir = 0;
    Pos cur = {.row = sta.row, .col = sta.col};
    Pos may;
    while (cur.row != end.row || cur.col != end.col) {
        may.row = cur.row + choice[dir][0];
        may.col = cur.col + choice[dir][1];
        if (may.row < 0 || may.row >= height || may.col < 0 || may.col >= width || maze[may.row][may.col] == '#') {
            dir = (dir + 1) % 4;
            continue;
        }
        cnt++;
        cur.row = may.row;
        cur.col = may.col;
        dir = (dir + 3) % 4;
    }
    return cnt;
}

int dfs_right(char** maze, int width, int height, Pos sta, Pos end) {
    int cnt = 1;
    int dir = 0;
    Pos cur = {.row = sta.row, .col = sta.col};
    Pos may;
    while (cur.row != end.row || cur.col != end.col) {
        may.row = cur.row + choice[dir][0];
        may.col = cur.col + choice[dir][1];
        if (may.row < 0 || may.row >= height || may.col < 0 || may.col >= width || maze[may.row][may.col] == '#') {
            dir = (dir + 3) % 4;
            continue;
        }
        cnt++;
        cur.row = may.row;
        cur.col = may.col;
        dir = (dir + 1) % 4;
    }
    return cnt;
}

int bfs(char** maze, int width, int height, Pos sta, Pos end) {
    Track* track = create(50);
    Pos* start = malloc(sizeof(Pos));
    start->row = sta.row; 
    start->col = sta.col; 
    start->step = 1;
    unsigned char** vis = malloc(sizeof(unsigned char*) * height);
    for (int i = 0; i < height; i++) {
        vis[i] = malloc(sizeof(unsigned char) * width);
        for (int j = 0; j < width; j++) {
            vis[i][j] = 0;
        }
    }

    push_back(track, start);
    vis[start->row][start->col] = 1;

    while (!is_empty(track)) {
        Pos* cur = pop_front(track);
        if (cur->col == end.col && cur->row == end.row) {
            return cur->step;
        }
        for (int i = 0; i < 4; i++) {
            Pos* may = malloc(sizeof(Pos));
            may->row = cur->row + choice[i][0];
            may->col = cur->col + choice[i][1];
            may->step = cur->step + 1;
            if (may->row < 0 || may->row >= height || may->col < 0 || may->col >= width || maze[may->row][may->col] == '#' || vis[may->row][may->col]) {
                continue;
            }
            push_back(track, may);
            vis[may->row][may->col] = 1;
        }
    }

    for (int i = 0; i < height; i++) {
        free(vis[i]);
    }
    free(vis);
    for (int i = 0; i < track->back; i++) {
        free(track->pos[i]);
    }
    free(track->pos);
    free(track);
    return -1;
}

int main() {
    int width = 9, height = 5;

    char temp[5][9] = {{'#', '#', '#', '#', '#', '#', '#', '#', '#'},
                       {'#', '.', '#', '.', '#', '.', '#', '.', '#'},
                       {'S', '.', '.', '.', '.', '.', '.', '.', 'E'},
                       {'#', '.', '#', '.', '#', '.', '#', '.', '#'},
                       {'#', '#', '#', '#', '#', '#', '#', '#', '#'}};

    char** maze = malloc(sizeof(char*) * height);
    for (int i = 0; i < height; i++) {
        maze[i] = malloc(sizeof(char) * width);
        for (int j = 0; j < width; j++) {
            maze[i][j] = temp[i][j];
        }
    }
    Pos sta, end;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (maze[i][j] == 'S') {
                sta.row = i; sta.col = j;
            }
            if (maze[i][j] == 'E') {
                end.row = i; end.col = j;
            }
        }
    }
    int res = dfs_left(maze, width, height, sta, end);
    res = dfs_right(maze, width, height, sta, end);
    res = bfs(maze, width, height, sta, end);

    for (int i = 0; i < height; i++) {
        free(maze[i]);
    }
    free(maze);
    return 0;
}
