/**
 * 2488. A Knight's Journey
 * http://poj.org/problem?id=2488
 * 
 */

/*
bool dfs(cur, stack, vis) {
    if cur == end { return true }
    stack.push(cur)
    vis{cur} = 1

    for (valid nxt in cur adj) {
        if (dfs(nxt, track, vis)) { return true }
        stack.pop
        vis{nxt} = 0
    }
    return false
}
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Location;

typedef struct {
    Location** loc;
    int back;
} Track;

Location* choice(Location* pre, int step) {
    Location* next = malloc(sizeof(Location));
    switch (step) {
        case 0: next->x = pre->x - 1; next->y = pre->y - 2; break;
        case 1: next->x = pre->x + 1; next->y = pre->y - 2; break;
        case 2: next->x = pre->x - 2; next->y = pre->y - 1; break;
        case 3: next->x = pre->x + 2; next->y = pre->y - 1; break;
        case 4: next->x = pre->x - 2; next->y = pre->y + 1; break;
        case 5: next->x = pre->x + 2; next->y = pre->y + 1; break;
        case 6: next->x = pre->x - 1; next->y = pre->y + 2; break;
        case 7: next->x = pre->x + 1; next->y = pre->y + 2; break;
    }
    return next;
}

void push_back(Track* tra, Location* loc) {
    tra->loc[tra->back++] = loc;
}

Location* pop_back(Track* tra) {
    return tra->loc[--tra->back];
}

int dfs(Track* track, Location* loc, int row, int col, int** vis) {
    if (track->back == col * row) {
        return 1;
    }

    for (int i = 0; i < 8; i++) {
        Location* next = choice(loc, i);
        if (next->x < 0 || next->x >= col || next->y < 0 || next->y >= row ) {
            continue;
        }
        if (vis[next->x][next->y] == 0) {
            vis[next->x][next->y] = 1;
            push_back(track, next);
            if (dfs(track, next, row, col, vis) == 1) {
                return 1;
            }
            vis[next->x][next->y] = 0;
            pop_back(track);
        }
        track->loc[track->back] = NULL;
        free(next);
    }
    return 0;
}

void print_res(Track* track, int num, int res) {
    printf("Scenario #%d:\n", num);
    if (res == 0) {
        printf("impossible\n");
    } else {
        for (int i = 0; i < track->back; i++) {
            Location* loc = track->loc[i];
            printf("%c%d", loc->x + 'A', loc->y + 1);
        }
        printf("\n");
    }
}

int main() {
    int total, row, col;
    scanf("%d", &total);

    int num = 0;
    while (num < total) {
        num++;
        scanf("%d %d", &row, &col);

        Location* start = malloc(sizeof(Location));
        start->x = 0; start->y = 0;

        Track* track = malloc(sizeof(Track));
        track->loc = malloc(sizeof(Location*) * (row * col));
        track->back = 0;

        int** vis = malloc(sizeof(int*) * row);
        for (int i = 0; i < row; i++) {
            vis[i] = malloc(sizeof(int) * col);
            for (int j = 0; j < col; j++) {
                vis[i][j] = 0;
            }
        }

        vis[0][0] = 1;
        push_back(track, start);
        int res = dfs(track, start, col, row, vis);

        print_res(track, num, res);

        for (int i = 0; i < row; i++) {
            free(vis[i]);
        }
        free(vis);
        for (int i = 0; i < track->back; i++) {
            free(track->loc[i]);
        }
        free(track->loc);
        free(track);
    }
    return 0;
}