#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h> //TODO: Use less libraries

//Complex number in trigonometric form: power of n calculator
//Version: 1.0b

typedef struct trigonometric_complex {
    float modulus;
    float argument;
} trig_cmp;

void trig_complex_power(float modulus, float argument, float power, unsigned int mode, FILE* out_file) {
    trig_cmp trig_num_temp;
    trig_num_temp.modulus = pow(modulus, power);
    trig_num_temp.argument = argument*power; //This isn't that complicated
    if(mode==0) {
        printf("%f %f", trig_num_temp.modulus, trig_num_temp.argument);
    }
    else if(mode==1) {
        fprintf(out_file, "%f %f\n", trig_num_temp.modulus, trig_num_temp.argument);
    }
}

int main(int argc, char** argv) {
    float modulus, argument, power;
    if(!strcmp(argv[1], "-d")) {
        modulus = atof(argv[2]);
        argument = atof(argv[3]);
        power = atof(argv[4]);
        trig_complex_power(modulus, argument, power, 0, 0);
    }
    else if(!strcmp(argv[1], "-f")) {
        FILE *in_file, *out_file;
        if(!(in_file=fopen(argv[2], "rb"))) {
            perror(argv[2]);
            return 1;
        }
        in_file = fopen(argv[2], "rb");
        out_file = fopen(argv[3], "wb");
        do{
            fscanf(in_file, "%f %f %f", &modulus, &argument, &power);
            trig_complex_power(modulus, argument, power, 1, out_file);
        } while(!feof(in_file));
        fclose(in_file);
        fclose(out_file);
    }
    else if(!strcmp(argv[1], "-b")) {
        clock_t tick = clock();
        for(int i=0; i<atoi(argv[2]); i++) {
            modulus = rand()%1000000;
            argument = rand()%1000000;
            power = rand()%1000;
            trig_complex_power(modulus, argument, power, 2, 0);
        }
        clock_t tock = clock();
        double benchmark_time = (double)(tock-tick)/CLOCKS_PER_SEC;
        printf("Benchmark time: %fms", benchmark_time); //Another weird way of benchmarking a computer
    }
return 0;
}
