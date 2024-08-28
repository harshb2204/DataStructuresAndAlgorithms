#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int frameSize = 1000; // Frame size in bits (not used directly in the calculations here)
    const double R = 60.0;      // Transmission rate in kbps
    const double RTT = 160.0;   // Round Tr
    const double OWPT = 80.0;   // One-Way Propagation Time in ms
    const int slidingWindowSize = 8;  // Sliding Window Size
    const double transmissionTimePerFrame = 20.0; // Time to put a frame on the wire in ms
    
    cout << setw(10) << "T (ms)" << setw(20) << "Frame Number" 
         << setw(10) << "->" << setw(20) << "Receiving Frame Number" 
         << setw(25) << "Time to Reach CPP (ms)" << endl;

    for (int i = 0; i < slidingWindowSize; ++i) {
        double T = i * transmissionTimePerFrame;
        int frameNumber = i + 1;
        double timeToReachCPP = T + transmissionTimePerFrame + OWPT;

        cout << setw(10) << T 
             << setw(20) << frameNumber 
             << setw(10) << "->" 
             << setw(20) << frameNumber 
             << setw(25) << timeToReachCPP << endl;
    }

    return 0;
}
