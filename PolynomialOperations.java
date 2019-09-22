package Polynomial;

import Structures.LinkedList;
import Structures.Node;
import java.util.ArrayList;

public abstract class PolynomialOperations
{
	// A method to add 2 polynomials
	public static LinkedList add(Node list1Head, Node list2Head)
	{
		LinkedList result = new LinkedList();
		Node current = list1Head;

		while(current != null)
		{
			result.insertSorted(current.getCoefficient(), current.getExponent());
			current = current.getNext();
		}

		Node current2 = list2Head;
		while(current2 != null)
		{
			result.insertSorted(current2.getCoefficient(), current2.getExponent());
			current2 = current2.getNext();
		}
		return result;
	}

	// A method to multiply 2 polynomials
	public static LinkedList multiply(Node list1Head, Node list2Head)
	{
		LinkedList result = new LinkedList();
		Node current = list1Head;

		while(current != null)
		{
			Node current2 = list2Head;
			while(current2 != null)
			{
				result.insertSorted(current.getCoefficient() * current2.getCoefficient(), current.getExponent() + current2.getExponent());
				current2 = current2.getNext();
			}
			current = current.getNext();
		}
		return result;
	}

	// A method to subtract 2 polynomials
	public static LinkedList subtract(Node list1Head, Node list2Head)
	{
		LinkedList result = new LinkedList();
		Node current = list1Head;
		while(current != null)
		{
			result.insertSorted(current.getCoefficient(), current.getExponent());
			current = current.getNext();
		}
		Node current2 = list2Head;
		while(current2 != null)
		{
			result.insertSorted(-1 * current2.getCoefficient(), current2.getExponent());
			current2 = current2.getNext();
		}
		return result;
	}

	// A method to substitute X's value in a polynomial
	public static double substitute(Node listHead, double variable)
	{
		double result = 0.0;
		Node current = listHead;
		while(current != null)
		{
			result += current.getCoefficient() * Math.pow(variable, current.getExponent());
			current = current.getNext();
		}
		return result;
	}

	// A method to add a list of polynomials
	public static LinkedList add(ArrayList<LinkedList> lists)
	{
		LinkedList result = new LinkedList();

		for(int i = 0; i < lists.size(); i++)
		{
			Node current = lists.get(i).getFirst();

			while(current != null)
			{
				result.insertSorted(current.getCoefficient(), current.getExponent());
				current = current.getNext();
			}
		}

		return result;
	}

	// A method to subtract a list of polynomials
	public static LinkedList subtract(ArrayList<LinkedList> lists)
	{
		LinkedList result = new LinkedList();

		for(int i = 0; i < lists.size(); i++)
		{
			Node current = lists.get(i).getFirst();

			if(i == 0)
			{
				while(current != null)
				{
					result.insertSorted(current.getCoefficient(), current.getExponent());
					current = current.getNext();
				}
			}
			else
			{
				while(current != null)
				{
					result.insertSorted(-1 * current.getCoefficient(), current.getExponent());
					current = current.getNext();
				}
			}

		}

		return result;
	}

	// A method to multiply a list of polynomials
	public static LinkedList multiply(ArrayList<LinkedList> lists)
	{
		LinkedList result;

		if(lists.size() > 1)
			result = multiply(lists.get(0).getFirst(), lists.get(1).getFirst());
		else
			result = lists.get(0);

		for(int i = 2; i < lists.size(); i++)
			result = multiply(result.getFirst(), lists.get(i).getFirst());


		return result;
	}
}
