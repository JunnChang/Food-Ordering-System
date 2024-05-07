void generateReport(item menu[], int count){
    for(int i = 0; i < count-1; i++){
        printf("%s: %d\n", menu[i].name, menu[i].sold);
    }
    return;
}