unitsize(1cm);
import libdado;

picture pic = dado(f = 4, t = 1, r = 2, rr = 1, show_axes = false);
add(pic.fit(3cm), (0,0), N);