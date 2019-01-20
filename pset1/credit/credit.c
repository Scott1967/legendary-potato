#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    long long input;

    long long cnum1 = 0;

    long long cnum2 = 0;

    long long cnum3 = 0;

    long long ccnum = 0;

    long long ccnum1 = 0;

    long long ccnum2 = 0;

    int count = 0;

    int num = 0;

    int num_mod = 0;

    int prekey = 0;

    int prekey1 = 0;

    int prekey2 = 0;

    int prekey3 = 0;

    int key = 0;

    int sum1 = 0;

    int sum2 = 0;

    int sum3 = 0;

    int checksum = 0;

    string card = "INVALID";

    bool factor0 = false;

    bool factor1 = false;

    bool factor2 = false;

    bool factor3 = false;

    bool factor4 = false;

    bool factor5 = false;

    bool factor6 = false;

    bool factor7 = false;

    bool factor8 = false;


    // get user's card number
    input = get_long_long("Card Number: ");


    // get count
    for (ccnum = input; ccnum > 0; ccnum /= 10)
    {
        count++;
    }


    // check validity of count
    if (count < 13)
    {
        factor7 = false;
    }

    if (count == 13)
    {
        factor7 = true;
    }

    if (count == 14)
    {
        factor7 = false;
    }

    if (count == 15)
    {
        factor7 = true;
    }

    if (count == 16)
    {
        factor7 = true;
    }

    if (count > 16)
    {
        factor7 = false;
    }


    // exit if count is not valid
    if (factor7 == false)
    {
        printf("%s\n", card);

        return 0;
    }


    // get key
    if (count % 2 == 0)
    {
        for (cnum1 = input; cnum1 > 0; cnum1 /= 100)
        {
            prekey = (cnum1 % 100);
        }

        prekey1 = prekey;

        if (prekey1 > 39 && prekey1 < 51)
        {
            prekey1 = (prekey1 / 10);
        }
        key = prekey1;
    }


    if (count == 13)
    {
        for (cnum2 = input; cnum2 > 0; cnum2 /= 100)
        {
            if (cnum2 == 4)
            {
                prekey2 = cnum2;
            }
        }
        key = prekey2;
    }


    if (count == 15)
    {
        for (cnum3 = input; cnum3 > 0; cnum3 /= 100)
        {
            if (cnum3 < 1000 && cnum3 > 99)
            {
                prekey3 = (cnum3 / 10);
            }
        }
        key = prekey3;
    }


    // check for nonvalid key
    if (key == 4) // VISA
    {
        factor8 = true;
    }

    if (key == 34) // AMEX
    {
        factor8 = true;
    }

    if (key == 37) // AMEX
    {
        factor8 = true;
    }

    if (key == 51) // MASTERCARD
    {
        factor8 = true;
    }

    if (key == 52) // MASTERCARD
    {
        factor8 = true;
    }

    if (key == 53) // MASTERCARD
    {
        factor8 = true;
    }

    if (key == 54) // MASTERCARD
    {
        factor8 = true;
    }

    if (key == 55) // MASTERCARD
    {
        factor8 = true;
    }


    if (factor8 == false)
    {
        printf("%s\n", card);

        return 0;
    }


    // go to last digit and count back every second digit
    for (ccnum1 = input; ccnum1 > 0; ccnum1 /= 100)
    {
        sum1 += (ccnum1 % 10);
    }


    // go to second last digit and count back every second digit
    for (ccnum2 = input; ccnum2 > 0; ccnum2 /= 100)
    {
        num_mod = (ccnum2 % 100);

        num = (num_mod / 10);

        sum2 = (2 * num);

        if (sum2 >= 10)
        {
            sum2 = ((sum2 - 10) + 1);
        }

        sum3 += sum2;

    }


    // add everything up
    checksum = (sum1 + sum3);


    // authenticate Luhn's algorithm
    if (checksum % 10 == 0)
    {
        factor0 = true;
    }
    else
    {
        factor0 = false;
    }


    if (factor0 == false)
    {
        card = "INVALID";

        printf("%s\n", card);

        return 0;
    }


    // check key for card type
    if (key == 34) // AMEX
    {
        factor1 = true;
    }

    if (key == 37) // AMEX
    {
        factor1 = true;
    }

    if (key == 51) // MASTERCARD
    {
        factor2 = true;
    }

    if (key == 52) // MASTERCARD
    {
        factor2 = true;
    }

    if (key == 53) // MASTERCARD
    {
        factor2 = true;
    }

    if (key == 54) // MASTERCARD
    {
        factor2 = true;
    }

    if (key == 55) // MASTERCARD
    {
        factor2 = true;
    }

    if (key == 4) // VISA
    {
        factor3 = true;
    }


    // check count
    if (count == 15) // AMEX
    {
        factor4 = true;
    }

    if (count == 16 && factor2 == true) // MASTERCARD
    {
        factor5 = true;
    }

    if (count == 13) // VISA
    {
        factor6 = true;
    }

    if (count == 16) // VISA
    {
        factor6 = true;
    }


    // verify card type
    if (factor0 == true && factor1 == true && factor4 == true)
    {
        card = "AMEX";

        printf("%s\n", card);

        return 0;
    }

    if (factor0 == true && factor2 == true && factor5 == true)
    {
        card = "MASTERCARD";

        printf("%s\n", card);

        return 0;
    }

    if (factor0 == true && factor3 == true && factor6 == true)
    {
        card = "VISA";

        printf("%s\n", card);

        return 0;
    }

}
