def shellSort(array, size):


    gap = size // 2
    while gap > 0:
        for i in range(gap, size):
            temp = array[i]
            j = i
            while j >= gap and array[j - gap] > temp:
                array[j] = array[j - gap]
                j -= gap

            array[j] = temp
        gap //= 2

    print(array)



def calculate_sequence(sequence, size):
    
    

    gaps = []

    if sequence == "SHELL":
        h = size
        while h > 1:
            gaps.append(h)
            h /= 2
        
        return gaps
    
    elif sequence == "KNUTH":
            
            h = 1 
            while h < size/3:
                h = h * 3 + 1
            
            gaps.append(h)
            
            while h > 1:
                h /= 3 
                gaps.append(h)

        return gaps


        case CIURA:
            //Calculate CIURA sequence
            vector<int> ciura = {1, 4 ,10 , 23, 57, 132, 301, 701};

            i = 0;
            h = 701;
            while(ciura.at(i) < array_size) {    

                if(ciura.at(i) > 701 || h > 701) {
                    h *= 2.25;
                    gaps.push_back(h);
                }else
                    gaps.push_back(ciura.at(i));
                i++;
            }

            reverse(gaps.begin(), gaps.end());
            return gaps;
            break;
    }