size(15cm);

// course = {start, finish, "height offset", "color"}
// where "color" is 0 for grey, 1 for green, 2 for red
int courses[][] = {
    {2, 9, 1, 1},
    {1, 3, 0, 2},
    {5, 7, 0, 2},
    {9, 10, 0, 2},
};

string labels[] = {
    "9",
    "3",
    "1",
    "2",
};

int left = courses[0][0];
int right = courses[0][1];
int highest_base = courses[0][2];

for (int i=0; i<courses.length; i+=1) {
    left = min(left, courses[i][0]);
    right = max(right, courses[i][1]);
    highest_base = max(highest_base, courses[i][2]);
}

real course_height = 0.3;

pen dotted = linetype(new real[]{4,4});
draw((left - 1, 0) -- (right, 0), dotted);
for (int i=left-1; i<=right; i+=1) {
    draw((i, 0) -- (i, 0.5 * highest_base + course_height), dotted);
}

for (int i=left; i<=right; i+=1) {
    label("$" + (string)i + "$", (i - 0.5, -0.2));
}

for (int i=0; i<courses.length; i+=1) {
    pen p;
    if (courses[i][3] == 0) {
        p = gray(0.8);
    } else if (courses[i][3] == 1) {
        p = rgb(0.5, 1, 0.5);
    } else {
        p = rgb(1, 0.5, 0.5);
    }

    real h = courses[i][2] * 0.5;

    filldraw(
        (courses[i][0]-1, h) --
        (courses[i][1], h) --
        (courses[i][1], h + course_height) --
        (courses[i][0]-1, h + course_height) --
        cycle,
        p
    );
}

for (int i=0; i<courses.length; i+=1) {
    real x = (courses[i][0] - 1 + courses[i][1]) * 0.5;
    real y = (courses[i][2] + course_height) * 0.5;
    filldraw(circle((x, y), 0.45 * course_height), rgb(0.7, 0.7, 1.0));
    label(labels[i], (x, y));
}
