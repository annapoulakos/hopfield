//hop.cpp
//Single layer Hopfield network with 4 neurons
#include "hop.h"

neuron::neuron (int *j) {
    int i;
    for (i = 0; i < 4; i++) {
        weightv[i] = *(j+i);
    }
}

int neuron::act (int m, int *x) {
    int i;
    int a = 0;
    for (i = 0; i < m; i++) {
        a += x[i] * weightv[i];
    }

    return a;
}

int network::threshold (int k) {
    if ( k >= 0) {
        return 1;
    } else {
        return 0;
    }
}

network::network (int a[4], int b[4], int c[4], int d[4]) {
    nrn[0] = neuron(a);
    nrn[1] = neuron(b);
    nrn[2] = neuron(c);
    nrn[3] = neuron(d);
}

void network::activation (int *patrn) {
    int i,j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            cout <<"\n nrn[" << i << "].weightv[" << j << "] is " << nrn[i].weightv[j];
        }

        nrn[i].activation = nrn[i].act(4,patrn);
        cout << "\nactivation is " << nrn[i].activation;
        output[i] = threshold(nrn[i].activation);
        cout << "\noutput value is " << output[i] << "\n";
    }
}

void main () {
    int patrn1[] = { 1, 0, 1, 0 }, i;
    int wt1[] = { 0, -3, 3, -3 };
    int wt2[] = { -3, 0, -3, 3 };
    int wt3[] = { 3, -3, 0, -3 };
    int wt4[] = { -3, 3, -3, 0 };

    cout << "\nThis program is for a Hopfield network with a single layer of ";
    cout << "\nfully interconnected neurons. THe network should recall the ";
    cout << "\npatterns 1010 and 0101 correctly.\n";

    //create network by calling its constructor.
    //the constructor calls neuron constructor as many times as the number of
    //neurons in the network.
    network h1(wt1, wt2, wt3, wt4);

    //present a patter to the network and get the activations of the neurons
    h1.activation(patrn1);

    //check if the pattern given is correctly recalled and give message.
    for (i = 0; i < 4; i++) {
        if (h1.output[i] == patrn1[i]) {
            cout << "\npattern = " << patrn1[i] << " output = " << h1.output[i] << " - component matches";
        } else {
            cout << "\npattern = " << patrn1[i] << " output = " << h1.output[i] << " - discrepancy occurred.";
        }
    }

    cout << "\n\n";
    int patrn2[] = { 0, 1, 0, 1 };
    h1.activation(patrn2);

    //check if the pattern given is correctly recalled and give message.
    for (i = 0; i < 4; i++) {
        if (h1.output[i] == patrn2[i]) {
            cout << "\npattern = " << patrn2[i] << " output = " << h1.output[i] << " - component matches";
        } else {
            cout << "\npattern = " << patrn2[i] << " output = " << h1.output[i] << " - discrepancy occurred.";
        }
    }
}
