class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total_length = nums1.size() + nums2.size();
        int nr1_position = 0, nr2_position = 0;
        int median_position = total_length / 2;
        bool is_even = (median_position * 2) == total_length;

        if (is_even)
        {
            median_position -= 1;
        }

        while ((nr1_position + nr2_position) < median_position)
        {
            if (nr1_position < nums1.size() && nr2_position < nums2.size())
            {
                if (nums1[nr1_position] < nums2[nr2_position])
                {
                    nr1_position++;
                }
                else
                {
                    nr2_position++;
                }
            }
            else if (nr1_position < nums1.size())
            {
                nr1_position++;
            }
            else
            {
                nr2_position++;
            }
        }

        double result;

        if (nr1_position < nums1.size() && nr2_position < nums2.size())
        {
            if (nums1[nr1_position] < nums2[nr2_position])
            {
                result = nums1[nr1_position];
                nr1_position++;
            }
            else
            {
                result = nums2[nr2_position];
                nr2_position++;
            }
        }
        else if (nr1_position < nums1.size())
        {
            result = nums1[nr1_position];
            nr1_position++;
        }
        else
        {
            result = nums2[nr2_position];
            nr2_position++;
        }

        if (is_even)
        {
            if (nr1_position < nums1.size() && nr2_position < nums2.size())
            {
                if (nums1[nr1_position] < nums2[nr2_position])
                {
                    result += nums1[nr1_position];
                    nr1_position++;
                }
                else
                {
                    result += nums2[nr2_position];
                    nr2_position++;
                }
            }
            else if (nr1_position < nums1.size())
            {
                result += nums1[nr1_position];
                nr1_position++;
            }
            else
            {
                result += nums2[nr2_position];
                nr2_position++;
            }

            result /= 2;
        }

        return result;
    }
};
