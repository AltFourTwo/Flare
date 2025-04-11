#pragma once

#include <concepts>
#include <type_traits>
#include <iterator>
#include <vector>
#include <string>

namespace Flare
{
   // Prototype of a property. WIP

   template <class ContainerType>
   concept Container = requires( ContainerType a, const ContainerType b )
   {
      requires std::regular<ContainerType>;
      requires std::swappable<ContainerType>;
      requires std::destructible<typename ContainerType::value_type>;
      requires std::same_as<typename ContainerType::reference, typename ContainerType::value_type&>;
      requires std::same_as<typename ContainerType::const_reference, const typename ContainerType::value_type&>;
      requires std::forward_iterator<typename ContainerType::iterator>;
      requires std::forward_iterator<typename ContainerType::const_iterator>;
      requires std::signed_integral<typename ContainerType::difference_type>;
      requires std::same_as<typename ContainerType::difference_type, typename std::iterator_traits<typename ContainerType::iterator>::difference_type>;
      requires std::same_as<typename ContainerType::difference_type, typename std::iterator_traits<typename ContainerType::const_iterator>::difference_type>;
      { a.begin() } -> std::same_as<typename ContainerType::iterator>;
      { a.end() } -> std::same_as<typename ContainerType::iterator>;
      { b.begin() } -> std::same_as<typename ContainerType::const_iterator>;
      { b.end() } -> std::same_as<typename ContainerType::const_iterator>;
      { a.cbegin() } -> std::same_as<typename ContainerType::const_iterator>;
      { a.cend() } -> std::same_as<typename ContainerType::const_iterator>;
      { a.size() } -> std::same_as<typename ContainerType::size_type>;
      { a.max_size() } -> std::same_as<typename ContainerType::size_type>;
      { a.empty() } -> std::same_as<bool>;
   };
   static_assert( Container<std::vector<unsigned char>> );
   static_assert( Container<std::string> );

   template<typename TStorage>
      requires Container<TStorage>
   class Collection
   {
      using TItem = typename TStorage::value_type;
      TStorage& m_Collection;

      public:
      Collection( TStorage& a_Collection ) :
         m_Collection(a_Collection)
      {}

      TItem& operator[]( const std::string& a_Key )
      {
         return m_Collection[0];
      }

      const TItem& operator[]( const std::string& a_Key ) const
      {
         return m_Collection[0];
      }
   };
}
