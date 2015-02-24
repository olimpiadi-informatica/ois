unitsize(1cm);
import libdado;

picture pic = dado(f = 2, t = 3, r = 6, rf = 1, rr = 1, show_axes = false);
add(pic.fit(3cm), (0,0), N);