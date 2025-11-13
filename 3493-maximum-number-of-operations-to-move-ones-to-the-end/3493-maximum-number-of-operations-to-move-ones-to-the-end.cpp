class Solution {
public:
int maxOperations(string s) {
        // Use long long for safety, as intermediate sums could be large,
        // although with N=50k, the sum 1...N fits in an int.
        // We will stick to the logic that worked and just change the name.
        // Re-evaluating: 1.25B fits in int. Using int is fine.
        
        int total_ops = 0;
        int active_ones = 0; // Tracks the size of the consolidated '1's block
        bool in_zero_gap = false;  // Tracks if we are currently in a '0' gap

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '1') {
                // We've found a '1'.
                if (in_zero_gap) {
                    // This '1' starts a new block after a gap.
                    // The previous consolidated block (size 'active_ones')
                    // must merge with this new block.
                    // This merge costs 'active_ones' operations.
                    total_ops += active_ones;
                    in_zero_gap = false; // We are no longer in a gap
                }
                // Add this '1' to the active consolidated block
                active_ones++;
            } else { // s[i] == '0'
                if (active_ones > 0) {
                    // We've found a '0' after a '1'.
                    // This marks the start or continuation of a zero gap.
                    in_zero_gap = true;
                }
            }
        }

        // After the loop, if we ended in a zero gap (e.g., "1100"),
        // the last consolidated block must merge with the "end".
        // This also costs 'active_ones' operations.
        if (in_zero_gap) {
            total_ops += active_ones;
        }

        return total_ops;
    }
};