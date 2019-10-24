package Structures;

public final class Node
{
	private double coefficient;
	private int exponent;
	private Node next;
	private Node previous;

	public Node(double coefficient, int exponent)
	{
		this.coefficient = coefficient;
		this.exponent = exponent;
	}

	public double getCoefficient()
	{
		return coefficient;
	}

	public int getExponent()
	{
		return exponent;
	}

	public Node getNext()
	{
		return next;
	}

	public Node getPrevious()
	{
		return previous;
	}

	public void setCoefficient(double coefficient)
	{
		this.coefficient = coefficient;
	}

	public void setExponent(int exponent)
	{
		this.exponent = exponent;
	}

	public void setNext(Node next)
	{
		this.next = next;
	}

	public void setPrevious(Node previous)
	{
		this.previous = previous;
	}

	public String toString()
	{
		String str = "";
		
		if(coefficient != 0)
		{
			if(exponent != 0)
			{
				if(exponent == 1)
				{
					if(coefficient == 1)
						str = "x";
					else if(coefficient == -1)
						str = "-x";
					else if(coefficient - (int) coefficient == 0)
						str = (int) coefficient + "x";
					else
						str = coefficient + "x";
				}
				else
				{
					if(coefficient == 1)
						str = "x^" + exponent;
					else if(coefficient == -1)
						str = "-x^" + exponent;
					else if(coefficient - (int) coefficient == 0)
						str = (int) coefficient + "x^" + exponent;
					else
						str = coefficient + "x^" + exponent;
				}
			}
			else
			{
				if(coefficient - (int) coefficient == 0)
					str = (int) coefficient + "";
				else
					str = coefficient + "";
			}
		}
		else
			str = " + ";
		
		return str;

		/*
		return coefficient != 0 ? exponent != 0 ? exponent == 1 ? coefficient == 1 ? coefficient + "" : coefficient - (int) coefficient == 0 ? (int) coefficient + "x" : coefficient + "x" : coefficient - (int) coefficient == 0 ? 
						(int) coefficient + "x^" + exponent : coefficient + "x^" + exponent : coefficient - (int) coefficient == 0 ? (int) coefficient + "" : coefficient + "" : "";*/
	}
}
