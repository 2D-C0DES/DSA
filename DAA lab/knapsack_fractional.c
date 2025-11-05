#include <stdio.h>

int num; // Number of items
float wt[100], val[100], ratio[100], frac[100], capacity;
int Index[100], original_Index[100]; // Arrays to store original indices

// Function to sort items based on profit-to-weight ratio in descending order
void sort() 
{
    for (int i = 1; i <= num; i++) 
    {
        for (int j = 1; j <= num - i; j++) 
        {
            if (ratio[j] < ratio[j + 1]) 
            {  
                // Swap ratio values
                float temp = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = temp;

                // Swap weight values
                temp = wt[j];
                wt[j] = wt[j + 1];
                wt[j + 1] = temp;

                // Swap value values
                temp = val[j];
                val[j] = val[j + 1];
                val[j + 1] = temp;

                // Swap original indices
                int tempIndex = Index[j];
                Index[j] = Index[j + 1];
                Index[j + 1] = tempIndex;
            }
        }
    }
}

// Function to perform fractional knapsack
float knapsack() 
{
    float total = 0; // Total profit
    for (int i = 1; i <= num; i++) 
    {
        if (wt[i] > capacity) 
        {
            frac[Index[i]] = capacity / wt[i]; // Store fraction in original index order
            total += val[i] * frac[Index[i]];  
            break; // Knapsack is full
        } 
        else 
        {
            frac[Index[i]] = 1; // Take full item
            total += val[i];
            capacity -= wt[i]; // Reduce capacity
        }
    }
    return total; // Return maximum profit
}

int main() 
{
    // Input number of items
    printf("Enter the number of items: ");
    scanf("%d", &num);

    // Input weights and values for each item
    for (int i = 1; i <= num; i++) 
    {
        printf("Enter weight and value for item %d: ", i);
        scanf("%f %f", &wt[i], &val[i]);
        ratio[i] = val[i] / wt[i];  // Calculate profit-to-weight ratio
        frac[i] = 0; // Initialize fractions
        Index[i] = i; // Store original index
    }

    // Input total knapsack capacity
    printf("Enter total weight capacity: ");
    scanf("%f", &capacity);

    sort(); // Sort items by ratio
    float maxProfit = knapsack(); // Get maximum profit

    // Output results
    printf("Maximum profit: %.2f\n", maxProfit);
    printf("Selected fractions of items in original order:\n");
    for (int i = 1; i <= num; i++) {
        printf("x[%d] = %.2f\n", i, frac[i]); // Print fractions in original input order
    }
    return 0;
}
