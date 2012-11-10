/*
 Markov - Fast Markov chain data mining.
 BSD license.
 by Sven Nilsen, 2012
 http://www.cutoutpro.com
 
 Version: 0.000
 Angular degrees version notation
 http://isprogrammingeasy.blogspot.no/2012/08/angular-degrees-versioning-notation.html
 
 */
/*
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.
 2. Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 The views and conclusions contained in the software and documentation are those
 of the authors and should not be interpreted as representing official policies,
 either expressed or implied, of the FreeBSD Project.
 */

#ifndef MARKOV_GUARD
#define MARKOV_GUARD

//
// Calculate the probability of changing state.
// This is known as a transition matrix.
// For use in game AI etc.
//
// cols		One column contains the history of an item.
//
// rows		One row contains the states at point in time.
//
// data		Contains the history of changes, one row per moment.
//
// states	The number of states.
//
// freq		Number of old measurments per state.
//			Used to weight the new knowlege relative to experience.
//			This array is updated with new values.
//
// prob		The transition matrix containing probability for changing
//			from one state (column) to another state (row).
//			Can be used for analyzing a system or simulate independent events.
//
// A markov chain can be updated using a single change of state.
// One reason to use a table with a row per moment is because it
// is easier to go back and look at the data and see what caused
// the Markov chain.
//
// It is possible to make things more complex, but often it is better
// to trying to isolate the dependent factors and either build it
// into the state or reduce the range of the Markov chain.
// Dependency often involes a moment, and using an array is simpler
// to search locally or compare Markov chains of different data sets.
//

void markov_chain
(int cols, int rows, const int data[], int states, int freq[], double prob[]);

#endif

