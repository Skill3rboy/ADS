#pragma once
#include <vector>
#include <map>
#include <ostream>
#include <queue>


namespace Utils
{
	template<typename T> struct is_vector : public std::false_type {};

	template<typename T, typename A>
	struct is_vector<std::vector<T, A>> : public std::true_type {};

	/**
	 * Gibt zurueck ob ein Vektor ein Element beinhaltet
	 *
	 * \param[in]  vect		Vektor
	 * \param[in]  element	Gesuchtes Element
	 * \return Beinhaltet der Vektor vect das Element element
	 */
	template <typename T>
	bool contains(const std::vector<T> vect, T element)
	{
		for (auto it = vect.begin(); it != vect.end(); it++)
		{
			if (*it == element) return true;
		}
		return false;
	}

	/**
	 * Entfernt ein Element im Vektor
	 *
	 * \param[in]  vect		Vektor
	 * \param[in]  element	Zu entfernendes Element
	 * \return Erfolgreich entfernt
	 */
	template <typename T>
	bool remove(std::vector<T>& vect, T element)
	{
		for (auto it = vect.begin(); it != vect.end(); it++)
		{
			if (*it == element) {
				vect.erase(it);
				return true;
			}
		}
		return false;
	}

	/**
	 * Gibt das Maximum eines Vektors zurueck
	 *
	 * \param[in]  vect		Vektor
	 * \return Maximum des Vectors vect
	 */
	template <typename T>
	T maximum(std::vector<T>& vect)
	{
		T maximum = vect[0];
		for (auto it = vect.begin() + 1; it != vect.end(); it++)
		{
			if (*it > maximum) {
				maximum = *it;
			}
		}
		return maximum;
	}

	/**
	 * Wrapper-Klasse um vergleiche unabhaengig von value zu ermoeglichen
	 *
	 * \tparam[in]  _CompareValueTyupe	Typ der compareValue
	 * \tparam[in]  _ValueType			Typ der value
	 */
	template <class _CompareValueTyupe, class _ValueType>
	class CompareContainer
	{
	public:
		_CompareValueTyupe compareValue;
		_ValueType value;

		/**
		 * Konstruktor
		 *
		 * \param[in]  compareValue		Anhand dieser Variable wird verglichen
		 * \param[in]  value			Variable fuer die ein Vergleich benoetigt wird
		 */
		CompareContainer(_CompareValueTyupe compareValue, _ValueType value) : compareValue{ compareValue }, value{ value } {}

		/**
		* Vergleicht zwei CompareContainer
		*
		* \param[in]  other		Container 2
		* \return true, wenn die compareValue von this und other gleich ist. Ansonsten false
		*/
		bool operator==(const CompareContainer& other) const { return compareValue == other.compareValue; }

		/**
		* Vergleicht zwei CompareContainer
		*
		* \param[in]  other		Container 2
		* \return true, wenn die compareValue von this und other ungleich ist. Ansonsten false
		*/
		bool operator!=(const CompareContainer& other) const { return !this->operator==(other); }

		/**
		* Vergleicht zwei CompareContainer
		*
		* \param[in]  other		Container 2
		* \return true, wenn die compareValue von this kleiner als die von other ist. Ansonsten false
		*/
		bool operator<(const CompareContainer& other) const { return compareValue < other.compareValue; }

		/**
		* Vergleicht zwei CompareContainer
		*
		* \param[in]  other		Container 2
		* \return true, wenn die compareValue von this groesser als die von other ist. Ansonsten false
		*/
		bool operator>(const CompareContainer& other) const { return !this->operator<(other) && !this->operator==(other); }

		/**
		* Vergleicht zwei CompareContainer
		*
		* \param[in]  other		Container 2
		* \return true, wenn die compareValue von this kleiner oder gleich, wie die von other ist. Ansonsten false
		*/
		bool operator<=(const CompareContainer& other) const { return !this->operator>(other); }

		/**
		* Vergleicht zwei CompareContainer
		*
		* \param[in]  other		Container 2
		* \return true, wenn die compareValue von this groesser oder gleich, wie die von other ist. Ansonsten false
		*/
		bool operator>=(const CompareContainer& other) const { return !this->operator<(other); }
	};

	/**
	 * Wrapper-Klasse um die Funktionsweise der std::priority_queue zu erweitern. Ermoeglicht es Objekte mit einem unabhaengigen Gewicht in die pq zu laden und erweitert die pq mit weiteren Methoden.
	 * Das kleinste Gewicht ist immer an Position top()
	 *
	 * \tparam[in]  _Tr			Datentyp der PriorityQueue
	 */
	template <typename _Tr>
	class PriorityQueue : public std::priority_queue<CompareContainer<double, _Tr>, std::vector<CompareContainer<double, _Tr>>, std::greater<CompareContainer<double, _Tr>>>
	{
	public:

		/**
		* Fuegt ein item mit dem Gewicht weight zur pq hinzu.
		*
		* \param[in]  item		Objekt was zur pq hinzugefuegt werden soll
		* \param[in]  weight	Das Gewicht mit dem item priorisiert werden soll
		*/
		void push(_Tr item, double weight)
		{
			std::priority_queue<CompareContainer<double, _Tr>, std::vector<CompareContainer<double, _Tr>>, std::greater<CompareContainer<double, _Tr>>>::push(CompareContainer<double, _Tr>(weight, item));
		}

		/**
		* Gibt das Item an Position top() zurueck und entfernt dieses aus der pq.
		*
		* \return Item an Position top()
		*/
		_Tr pop_top()
		{
			_Tr item = this->top().value;
			this->pop();
			return item;
		}

		/**
		* Entfernt element aus der pq und gibt zurueck, ob es gefunden und entfernt wurde.
		*
		* \return true, wenn element aus der pq entfernt wurde, sonst false
		*/
		bool remove(const _Tr& element)
		{
			for (auto it = this->c.begin(); it != this->c.end(); it++)
			{
				if ((*it).value == element) {
					this->c.erase(it);
					return true;
				}
			}
			return false;
		}

		/**
		* Sucht nach element in der pq und gibt zurueck ob es gefunden wurde
		*
		* \return true, wenn element in der pq gefunden wurde, sonst false
		*/
		bool contains(const _Tr& element)
		{
			for (auto it = this->c.begin(); it != this->c.end(); it++)
			{
				if ((*it).value == element) {
					return true;
				}
			}
			return false;
		}

		/**
		* Tauscht das Gewicht von element aus und gibt zurueck ob es gefunden wurde.
		*
		* \return true, wenn element in der pq gefunden wurde, sonst false
		*/
		bool change(const _Tr& element, double weight)
		{
			if (!remove(element)) return false;
			this->push(element, weight);
			return true;
		}
	};
}

namespace PrintUtils
{

	/**
	 * Gibt einen Vektor aus
	 *
	 * \param[in]  stream	Ausgabestream
	 * \param[in]  vect		Der auszugebende Vektor
	 * \return Ausgabestream
	 */
	template <typename T>
	std::ostream& operator<< (std::ostream& stream, const std::vector<T>& vect)
	{
		stream << "{" << (Utils::is_vector<T>{} ? "\n" : " ");
		for (int i = 0; i < vect.size(); i++)
		{
			if (Utils::is_vector<T>{})
			{

				stream << "  " << i << ": " << vect[i] << std::endl;
			}
			else
			{
				stream << vect[i] << (i < vect.size() - 1 ? ", " : " ");
			}
		}
		stream << "}";
		return stream;
	}

	/**
	 * Gibt eine Map aus
	 *
	 * \param[in]  stream	Ausgabestream
	 * \param[in]  m		Die auszugebende Map
	 * \return Ausgabestream
	 */
	template <typename T>
	std::ostream& operator<< (std::ostream& stream, const std::map<int, T>& m)
	{
		bool first = true;
		stream << "{" << std::endl;
		for (auto const& val : m)
		{
			if (Utils::is_vector<T>{})
			{

				stream << "  " << val.first << ": " << val.second << std::endl;
			}
			else
			{
				stream << (!first ? ", " : " ") << val.second;
				first = false;
			}
		}
		stream << "}";
		return stream;
	}
}