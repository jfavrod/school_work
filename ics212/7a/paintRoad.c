int costofpainting(double x) {
    int fee = 0;

    if (x > 2) {
        int i = 0;
        while (i < 3) {
            fee = fee + costofpainting(x/3.0);
            i++;
        }
        return fee + 100;
    }
    else if (x > 0) {
        return 200;
    }
    
    return 0;
}
