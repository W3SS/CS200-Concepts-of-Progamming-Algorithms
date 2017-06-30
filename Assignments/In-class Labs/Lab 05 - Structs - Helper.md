# CS 200 Lab 05: Structs - Helper

# Structs

Structs (and later on, Classes) are a way for the programmer to create their own
*data types*. We can put together multiple variables in one container, and give
that container a name to describe the object.

For example, if you're trying to store a list of students, it would be annoying to
work with several arrays for each field:

```c++
string studentNames[100];
float studentGpas[100];
string studentDegree[100];
```

Rather than making several arrays of each field, why not group each field
together under a "Student" object, and make an array of students?

```c++
// OUTSIDE OF ALL FUNCTIONS:
struct Student
{
	string name;
	float gpa;
	string degree;
};

// In main or another function:
Student studentList[100];
```

Using the **Student** object above, let's just work with a single Student
variable for now, and step through how we use it.

```c++
int main()
{
	Student me;
	
	return 0;
}
```

To set those fields, *name*, *gpa*, and *degree*, which are *contained within Student*,
we use the dot operator . with the variable:

```c++
me.name = "Rach";
me.gpa = 3.2;
me.degree = "Computer Science";
```

So now all this information is stored within three variables (strings and a float), but these three
variables also *belong* to a single Student variable.

We can also have our array of students:

```c++
Student studentList[100];
```

and we can set each student's internal variables as well:

```c++
studentList[0].name = "Takahiro";
studentList[0].degree = "Mathematics";

studentList[1].name = "Carla";
studentList[1].degree = "Civil Engineering";
```

We can also store **functions** within our struct object.

```c++
struct Student
{
	string name;
	float allGrades[100];
	int classesTaken;
	string degree;
	
	float GetGPA()
	{
		float sum = 0;
		for ( int i = 0; i < classesTaken; i++ )
		{
			sum += allGrades[i];
		}
		return sum / classesTaken;
	}
};
```

Then, our function can be called from the object itself:

```c++
cout << "NAME: " << studentList[0] << ", GPA: " << studentList[0].GetGPA() << endl;
```

The **variables** and **functions** within a struct are known as **members**.
They belong to the struct, and when you declare a variable of that struct type,
that variable will contain those variables and functions.
