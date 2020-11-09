#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

void quicksort(int* arr, int  end, int begin) {
    int mid;
    int f = begin;
    int l = end;
    mid = arr[(f + l) / 2];
    while (f < l)
    {
        while (arr[f] < mid) f++;
        while (arr[l] > mid) l--;
        if (f <= l)
        {
            swap(arr[f], arr[l]);
            f++;
            l--;
        }
    }
    if (begin < l) quicksort(arr, l, begin);
    if (f < end) quicksort(arr, end, f);
}

int binarySearch(int array[], int x, int low, int high) {

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (array[mid] == x)
            return mid;

        if (array[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    const int N = 100;
    int unsortArr[N];
    int arr[N];

    cout << "\nLet's make some array and sort it to realize other tasks\n";
  
    int answer;
    answer = 0;

    while (answer != 2) {
        cout << "\nTo make new array, enter 1\n";
        cout << "To exit, enter 2 \n";
        cin >> answer;
        system("CLS");

        switch (answer)
        {
        case (1):
        {
            // создаем рандомный массив из 100 чисел от -99 до 99
            for (int i = 0; i < N; i++) {
                unsortArr[i] = -99 + (rand() % 200);
            }

            for (int i = 0; i < N; ++i)
                arr[i] = unsortArr[i];

            // сортируем массив с помощью quick sort
            auto startQuick = std::chrono::high_resolution_clock::now();
            int end, begin;
            end = N - 1;
            begin = 0;
            quicksort(arr, end, begin);
            auto endQuick = std::chrono::high_resolution_clock::now();
            auto timeQuick = std::chrono::duration_cast<std::chrono::nanoseconds>(endQuick - startQuick);

            cout << "\nTime spent on sorting (nanoseconds): " << std::fixed << timeQuick.count() << endl;

            int answer2;
            answer2 = 0;

            while (answer2 != 9) {
                cout << "\nUnsorted array: \n";
                for (int i = 0; i < N; i++)
                    cout << unsortArr[i] << " ";

                cout << "\n\nSorted array: \n";
                for (int i = 0; i < N; i++)
                    cout << arr[i] << " ";

                cout << "\n\nWhat tasks do you wanna check? (Write task's number)\n";
                cout << "3. Find the maximum and minimum element of the array. Calculate the search time in sorted and unsorted arrays using the chrono library;\n";
                cout << "4. Output the average value of the maximum and minimum values. Print the indexes of all elements that are equal to this value, and their number.\n";
                cout << "5. Print the number of elements in the sorted array that are less than the number that is initialized by the user;\n";
                cout << "6. Print the number of elements in the sorted array that are greater than the number that is initialized by the user;\n";
                cout << "7. Output information about whether the number entered by the user is in the sorted array;\n";
                cout << "8. Swaps array elements whose indexes are entered by the user.\n";
                cout << "To make new array or exit, enter 9 \n";
                cin >> answer2;
                system("CLS");

                switch (answer2)
                {
                case (3):
                {
                    int minInUnsorted, maxInUnsorted;
                    minInUnsorted = 0;
                    maxInUnsorted = 0;

                    auto startFindingUn = std::chrono::high_resolution_clock::now();
                    for (int i = 0; i < N; i++)
                    {
                        if (unsortArr[i] <= minInUnsorted)
                        {
                            minInUnsorted = unsortArr[i];
                        }
                        if (unsortArr[i] >= maxInUnsorted)
                        {
                            maxInUnsorted = unsortArr[i];
                        }
                    }
                    cout << "\nMinimum element of an unsorted array: " << minInUnsorted;
                    cout << "\nMaximum element of an unsorted array: " << maxInUnsorted;
                    auto endFindingUn = std::chrono::high_resolution_clock::now();
                    auto timeFindingUn = std::chrono::duration_cast<std::chrono::nanoseconds>(endFindingUn - startFindingUn);
                    cout << "\nTime spent on unsorted finding (nanoseconds): " << std::fixed << timeFindingUn.count() << endl;

                    auto startFindingSo = std::chrono::high_resolution_clock::now();
                    cout << "\nMinimum element of the sorted array: " << arr[0];
                    cout << "\nMaximum element of the sorted array: " << arr[99];
                    auto endFindingSo = std::chrono::high_resolution_clock::now();
                    auto timeFindingSo = std::chrono::duration_cast<std::chrono::nanoseconds>(endFindingSo - startFindingSo);
                    cout << "\nTime spent on sorted finding (nanoseconds): " << std::fixed << timeFindingSo.count() << endl;
                
                    break;
                }

                case (4):
                    int average;

                    average = round((arr[0] + arr[99]) / 2);
                    cout << "\nThe average value of the maximum and minimum values: " << average;
                    cout << "\nIndexes of all elements that are equal to this value: ";
                    int numberInArray;
                    numberInArray = 0;
                    for (int i = 0; i < 100; i++) {
                        if (unsortArr[i] == average) {
                            numberInArray += 1;
                            cout << "\n" << i << "\n";
                        }
                    }
                    cout << "Total of these in the array: " << numberInArray << "\n";

                    break;

                case (5):
                    cout << "To search for elements in the sorted array that are less than the number a, enter a: ";
                    int a;
                    int lowerThanA;
                    lowerThanA = 0;
                    cin >> a;
                    for (int i = 0; i < N; i++) {
                        if (arr[i] < a) {
                            lowerThanA += 1;
                        }
                    }
                    cout << "\nElements less than a: " << lowerThanA << endl;
                    break;

                case (6):
                    cout << "To search for elements in the sorted array that are greater than the number b, enter b: ";
                    int b;
                    int higherThanB;
                    higherThanB = 0;
                    cin >> b;
                    for (int i = 0; i < N; i++) {
                        if (arr[i] > b) {
                            higherThanB += 1;
                        }
                    }
                    cout << "\nElements greater than  b: " << higherThanB << endl;
                    break;

                case (7):
                {
                    int x;
                    bool answer7;
                    bool isExists = false;

                    cout << "\nUnsorted array: \n";
                    for (int i = 0; i < N; i++)
                        cout << unsortArr[i] << " ";

                    cout << "\n\nSorted array: \n";
                    for (int i = 0; i < N; i++)
                        cout << arr[i] << " ";

                    while (true) {
                        cout << "\nWhat integer do you want to find? \n";
                        cin >> x;

                        auto startSort = std::chrono::high_resolution_clock::now();
                        for (int i = 0; i < N; i++) {
                            if (arr[i] == x) {
                                isExists = true;
                                break;
                            }
                        }
                        auto endSort = std::chrono::high_resolution_clock::now();
                        auto timeSort = std::chrono::duration_cast<std::chrono::nanoseconds>(endSort - startSort);
                        cout << "\nTime spent on regular sorted finding (nanoseconds): " << std::fixed << timeSort.count() << endl;

                        auto startBinary = std::chrono::high_resolution_clock::now();
                        int result = binarySearch(arr, x, 0, N - 1);
                        auto endBinary = std::chrono::high_resolution_clock::now();
                        auto timeBinary = std::chrono::duration_cast<std::chrono::nanoseconds>(endBinary - startBinary);
                        cout << "\nTime spent on binary sorted finding (nanoseconds): " << std::fixed << timeBinary.count() << endl;
                        
                        if (result == -1)
                            cout << "Not found" << "\n";
                        else
                            cout << "Element is found at index " << result << "\n";

                        cout << fixed << "\nDifference between Binary search and regular search (nanoseconds): " << timeSort.count() - timeBinary.count() << "\n";

                        cout << "\nExit? 1/0";
                        cin >> answer7;
                        if (answer7) {
                            system("CLS");
                            break;
                        }
                    }
                    break;
                }

                case (8):
                {
                    bool answer8;
                    cout << "\nUnsorted array: \n";
                    for (int i = 0; i < N; i++)
                        cout << unsortArr[i] << " ";

                    while (true) {
                            cout << "\nTo swap two array elements, enter their indexes: \n";
                            int first;
                            int second;
                            cout << "First: ";
                            cin >> first;
                            cout << "Second: ";
                            cin >> second;
                            cout << "\n";

                            auto startSwap = std::chrono::high_resolution_clock::now();
                            swap(unsortArr[first], unsortArr[second]);
                            auto endSwap = std::chrono::high_resolution_clock::now();
                            auto timeSwap = std::chrono::duration_cast<std::chrono::nanoseconds>(endSwap - startSwap);
                            cout << "\nTime spent on swaping(nanoseconds): " << std::fixed << timeSwap.count() << endl;

                            cout << "\nUnsorted array: \n";
                            for (int i = 0; i < N; i++)
                                cout << unsortArr[i] << " ";

                            cout << "\nExit? 1/0";
                            cin >> answer8;
                            if (answer8) {
                                system("CLS");
                                break;
                            }
                    }
                    break;
                }

                case (9):
                    break;

                default:
                    cout << "Oh, no! This task doesn't exist. Let's try again.\n";
                    break;
                }
            }
            break;
        }

        case (2):
            cout << "Have a nice day!\n";
            break;

        default:
            cout << "Oh, no! This task doesn't exist. Let's try again.\n";
            break;
        }
    }
    return 0;
}
