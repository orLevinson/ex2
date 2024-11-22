/******************
Name:
ID:
Assignment: ex2
*******************/

#include <stdio.h>

int main()
{

	int choice;

	// while the user doesn't want to exit continue the loop
	while (choice != 7)
	{

		// print the menu
		printf("Choose an option:\n");
		printf("\t1. Happy Face\n");
		printf("\t2. Balanced Number\n");
		printf("\t3. Generous Number\n");
		printf("\t4. Circle Of Joy\n");
		printf("\t5. Happy Numbers\n");
		printf("\t6. Festival Of Laughter\n");
		printf("\t7. Exit\n");

		scanf(" %d[^\n]", &choice);

		switch (choice)
		{
		case 1:
			// Case 1: Draw Happy Face with given symbols for eyes, nose and mouse
			/* Example:
			 * n = 3:
			 * 0   0
			 *   o
			 * \___/
			 */
			char eyes, nose, mouse;
			int size = 0;
			printf("Enter symbols for the eyes, nose, and mouse:\n");
			scanf(" %c %c %c", &eyes, &nose, &mouse);
			while (size < 1)
			{
				// if there is an error
				if (size == -1)
				{
					printf("Invalid face size, please try again.\n");
				}
				else
				{
					printf("Enter face size:\n");
				}
				scanf(" %d", &size);
				// if size is less then 1 or isnt odd
				if (size < 1 || size % 2 != 1)
				{
					// error code
					size = -1;
				}
			}
			// make the eyes
			for (int i = 0; i < size + 2; i++)
			{
				printf("%c", (i == 0 || i == size + 1) ? eyes : ' ');
			}
			printf("\n");
			// make the nose
			for (int i = 0; i < size + 2; i++)
			{
				printf("%c", (i == (size + 1) / 2) ? nose : ' ');
			}
			printf("\n");
			// make the mouth
			for (int i = 0; i < size + 2; i++)
			{
				if (i == 0)
				{
					printf("\\");
				}
				else if (i == size + 1)
				{
					printf("/");
				}
				else
				{
					printf("%c", mouse);
				}
			}
			printf("\n");
			break;

		case 2:
			// Case 2: determine whether the sum of all digits to the left of the middle digit(s)
			// and the sum of all digits to the right of the middle digit(s) are equal
			/* Examples:
			Balanced: 1533, 450810, 99
			Not blanced: 1552, 34
			Please notice: the number has to be bigger than 0.
			*/
			int number = 0;
			while (number < 1)
			{
				if (number == -1)
				{
					printf("Only positive number is allowed, please try again:\n");
				}
				else
				{
					printf("Enter a number:\n");
				}
				scanf(" %d", &number);
				if (number < 1)
				{
					// error code
					number = -1;
				}
			}

			// get the length of the int
			unsigned int length = 0;
			int temp = number;
			while (temp > 0)
			{
				temp = (temp - temp % 10) / 10;
				length++;
			}
			// start aggregating the values
			temp = number;
			unsigned int left = 0, right = 0;
			for (int i = 1; i <= length; i++)
			{
				// current val
				int val = temp % 10;
				temp = (temp - temp % 10) / 10;

				// i+1 current index
				if (i < length - (i - 1))
				{
					right += val;
				}
				else if (i > length - (i - 1))
				{
					left += val;
				}
				else
				{
					left += val;
					right += val;
				}
				// checks for each iteration - printf("this is the %d loop: right - %d, left - %d\n",i,right,left);
			}
			if (left == right)
			{
				printf("This number is balanced and brings harmony!\n");
			}
			else
			{
				printf("This number isn't balanced and destroys harmony.\n");
			}

			break;

		case 3:
			// Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
			/* Examples:
			Abudant: 12, 20, 24
			Not Abudant: 3, 7, 10
			Please notice: the number has to be bigger than 0.
			*/
			number = 0;
			while (number < 1)
			{
				if (number == -1)
				{
					printf("Only positive number is allowed, please try again:\n");
				}
				else
				{
					printf("Enter a number:\n");
				}
				scanf(" %d", &number);
				if (number < 1)
				{
					// error code
					number = -1;
				}
			}

			int sumOfDivisors = 0;
			for (int i = 1; i < number; i++)
			{
				// check if i is a divisor of the number
				if (number % i == 0)
				{
					// if yes add to the sum
					sumOfDivisors += i;
				}
			}
			if (sumOfDivisors > number)
			{
				printf("This number is generous!\n");
			}
			else
			{
				printf("This number does not share.\n");
			}
			break;

		case 4:
			// Case 4: determine wether a number is a prime.
			/* Examples:
			This one brings joy: 3, 5, 11
			This one does not bring joy: 15, 8, 99
			Please notice: the number has to be bigger than 0.
			*/
			number = 0;
			while (number < 1)
			{
				if (number == -1)
				{
					printf("Only positive number is allowed, please try again:\n");
				}
				else
				{
					printf("Enter a number:\n");
				}
				scanf(" %d", &number);
				if (number < 1)
				{
					// error code
					number = -1;
				}
			}
			int reversedNumber = 0;
			temp = number;
			// make a reversed version of the number
			while (temp > 0)
			{
				reversedNumber = reversedNumber * 10 + temp % 10;
				temp = (temp - temp % 10) / 10;
			}

			// check edge cases
			if (number == 1)
			{
				printf("The circle remains incomplete.\n");
				break;
			}

			char isCircleBroken = 0;
			// check the original and reversed number
			for (int i = 2; i < number; i++)
			{
				if (number % i == 0)
				{
					isCircleBroken++;
					break;
				}
			}

			for (int i = 2; i < reversedNumber; i++)
			{
				if (reversedNumber % i == 0 || isCircleBroken)
				{
					isCircleBroken++;
					break;
				}
			}

			if (isCircleBroken)
			{
				printf("The circle remains incomplete.\n");
			}
			else
			{
				printf("This number completes the circle of joy!\n");
			}

			break;

		case 5:
			// Happy numbers: Print all the happy numbers between 1 to the given number.
			// Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
			/* Examples:
			Happy :) : 7, 10
			Not Happy :( : 5, 9
			Please notice: the number has to be bigger than 0.
			*/
			number = 0;
			while (number < 1)
			{
				if (number == -1)
				{
					printf("Only positive number is allowed, please try again:\n");
				}
				else
				{
					printf("Enter a number:\n");
				}
				scanf(" %d", &number);
				if (number < 1)
				{
					// error code
					number = -1;
				}
			}
			printf("Between 1 and %d only these numbers bring happiness: ", number);
			for (int i = 1; i <= number; i++)
			{
				int digits = i;
				int steps = 0;
				// every none happy number is periodic every 8 steps
				while (digits != 1 && steps < 8)
				{
					int temp = digits;
					int sumOfDigits = 0;
					while (temp > 0)
					{
						sumOfDigits += (temp % 10) * (temp % 10);
						temp = (temp - temp % 10) / 10;
					}
					digits = sumOfDigits;
					steps++;
				}
				if (digits == 1)
				{
					printf("%d ", i);
				}
			}
			printf("\n");
			break;

		case 6:
			// Festival of Laughter: Prints all the numbers between 1 the given number:
			// and replace with "Smile!" every number that divided by the given smile number
			// and replace with "Cheer!" every number that divided by the given cheer number
			// and replace with "Festival!" every number that divided by both of them
			/* Example:
			6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
			*/

			int smileValue = 0, cheerValue = 0;
			char smileLabel[20], cheerLabel[20]; // To store the labels for checking

			// Read the labels and values with specific format
			//   printf("%d %d\n", smileValue, cheerValue);
			while (smileValue < 1 || cheerValue < 1)
			{
				if (smileValue == 0 && cheerValue == 0)
				{
					printf("Enter a smile and cheer number:\n");
				}
				else
				{
					printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:");
				}

				// check for the following template:
				// <20-char-long-str>: <int><20-char-long-str>: <int>
				scanf(" %20[^:\n\t]: %d%20[^:\n\t]: %d", smileLabel, &smileValue, cheerLabel, &cheerValue);

				// trim smileLabel and cheerLabel and also removing the ','
				int cheerIdx = 0;
				int smileIdx = 0;
				for (int i = 0; i < 20; i++)
				{
					if (cheerLabel[i] != ' ' && cheerLabel[i] != ',')
					{
						cheerLabel[cheerIdx++] = cheerLabel[i];
					}
					if (smileLabel[i] != ' ')
					{
						smileLabel[smileIdx++] = smileLabel[i];
					}
				}
				// clearing the rest of cheerLabel and smileLabel
				for (int i = cheerIdx; i < 20; i++)
				{
					cheerLabel[i] = '\0';
				}
				for (int i = smileIdx; i < 20; i++)
				{
					smileLabel[i] = '\0';
				}

				// check if the labels match "smile" and "cheer"
				char smileLabelValue[] = "smile";
				char cheerLabelValue[] = "cheer";
				for (int i = 0; i < 20; i++)
				{
					// if there are letters in the current iteration smileLabelValue or cheerLabelValue
					// it is ok to do them both in the same logical check because they have the same number of letters
					// the same goes for checking if their values match to the labels in the input
					if (cheerLabelValue[i] != '\0' || smileLabelValue[i] != '\0')
					{
						if (cheerLabel[i] != cheerLabelValue[i] || smileLabel[i] != smileLabelValue[i])
						{
							smileValue = -1;
							cheerValue = -1;
							break;
						}
					}
					else
					{
						// check if the inputted labels end together with the provided values
						if (cheerLabel[i] != '\0' || smileLabel[i] != '\0')
						{
							smileValue = -1;
							cheerValue = -1;
						}
						break;
					}
				}
			}

			// if the nums are not postive or match
			if (smileValue < 1 || cheerValue < 1 || smileValue == cheerValue)
			{
				for (int i = 0; i < 20; i++)
				{
					cheerLabel[i] = '\0';
					smileLabel[i] = '\0';
				}
				smileValue = -1;
				cheerValue = -1;
			}

			number = 0;
			while (number < 1)
			{
				if (number != -1)
				{
					printf("Enter maximum number for the festival:\n");
				}
				else
				{
					printf("Only positive maximum number is allowed, please try again:\n");
				}
				scanf(" %d", &number);
				if (number < 1)
				{
					// error code
					number = -1;
				}
			}

			for (int i = 1; i <= number; i++)
			{
				if (i % cheerValue == 0 && i % smileValue == 0)
				{
					printf("Festival!\n");
				}
				else if (i % cheerValue == 0)
				{
					printf("Cheer\n");
				}
				else if (i % smileValue == 0)
				{
					printf("Smile!\n");
				}
				else
				{
					printf("%d\n", i);
				}
			}
			break;
		
		case 7: break;

		default:
			printf("This option is not available, please try again.\n");
			break;
		}
	}

	return 0;
}