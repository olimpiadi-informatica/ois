unitsize(1cm);
import libdado;

picture pic = dado(f = 1, t = 5, r = 3, rr = 1, show_axes = false);
add(pic.fit(3cm), (0,0), N);