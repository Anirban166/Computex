package Structures;

public final class LinkedList
{
	private Node first;

	public LinkedList()
	{
	}

	public Node getFirst()
	{
		return first;
	}

	public void InsertFirst(double coefficient, int exponent)
	{
		Node newNode = new Node(coefficient, exponent);
		if(first == null)
			first = newNode;
		else
		{
			first.setPrevious(newNode);
			newNode.setNext(first);
			first = newNode;
		}
	}

	public void InsertLast(double coefficient, int exponent)
	{
		Node newNode = new Node(coefficient, exponent);
		if(first == null)
			first = newNode;
		else
		{
			Node current = first;
			while(current.getNext() != null)
				current = current.getNext();
			current.setNext(newNode);
			newNode.setPrevious(current);
		}
	}

	// A method to insert a Node to the linkedList in a sorted way
	public void insertSorted(double coefficient, int exponent)
	{
		Node newNode = new Node(coefficient, exponent);
		Node current = first;

		while(current != null && current.getExponent() > exponent)
			current = current.getNext();

		if(current != null && current.getExponent() == exponent)
			current.setCoefficient(current.getCoefficient() + coefficient);
		else if(current == first)
			InsertFirst(coefficient, exponent);
		else if(current == null)
			InsertLast(coefficient, exponent);
		else
		{
			newNode.setPrevious(current.getPrevious());
			newNode.setNext(current);
			current.getPrevious().setNext(newNode);
			current.setPrevious(newNode);
		}
	}

	public int size()
	{
		int index = 0;
		Node current = first;

		while(current != null)
		{
			index++;
			current = current.getNext();
		}

		return index;
	}

	public boolean isEmpty()
	{
		return first == null;
	}

	@Override
	public String toString()
	{
		Node current = first;
		String returned = "";
		while(current.getNext() != null)
		{
			if(current.getCoefficient() != 0 && current.getNext().getCoefficient() != 0)
				returned += current + " + ";
			else
				returned += current;
			current = current.getNext();
		}

		if(!current.toString().equals(" + "))
			returned += current.toString();

		if(returned.toString().startsWith(" + "))
			returned = returned.substring(3, returned.length());

		return returned;
	}
}
