// #include <memory>
// #include <unordered_map>

// template <typename K, typename V>
// struct CopyUnorderedMap {
//     static std::unique_ptr<std::unordered_map<K, V>> copy(const std::unique_ptr<std::unordered_map<K, V>> &unorderedMap) {
//         if (!unorderedMap) {
//             return nullptr; // Return a nullptr if the input is null
//         }

//         auto newUnorderedMap = std::make_unique<std::unordered_map<K, V>>();
//         for (const auto &pair : *unorderedMap) {
//             newUnorderedMap->emplace(pair.first, pair.second);
//         }
//         return std::move(newUnorderedMap);
//     }
// };

// // Specialization for copying a std::unordered_map
// template <typename K, typename V>
// struct CopyUnorderedMap<K, std::unique_ptr<std::unordered_map<K, V>>> {
//     static std::unique_ptr<std::unordered_map<K, std::unique_ptr<std::unordered_map<K, V>>>>
//     copy(const std::unique_ptr<std::unordered_map<K, std::unique_ptr<std::unordered_map<K, V>>>>
//         &unorderedMap) {
//         if (!unorderedMap) {
//             return nullptr; // Return a nullptr if the input is null
//         }

//         auto newUnorderedMap = std::make_unique<std::unordered_map<K, std::unique_ptr<std::unordered_map<K, V>>>();
//         for (const auto &pair : *unorderedMap) {
//             if (pair.second) {
//                 newUnorderedMap->emplace(pair.first, std::make_unique<std::unordered_map<K, V>>(*(pair.second)));
//             } else {
//                 newUnorderedMap->emplace(pair.first, nullptr);
//             }
//         }
//         return std::move(newUnorderedMap);
//     }
// };

// template <typename K, typename V>
// std::unique_ptr<V> copy(const std::unique_ptr<V> &value) {
//     if (value) {
//         return std::make_unique<typename V::element_type>(*value);
//     }
//     return nullptr;
// }

// // Convenience function to choose the appropriate copy function based on the type
// template <typename K, typename V>
// std::unique_ptr<V> copyUnorderedMap(const std::unique_ptr<V> &value) {
//     return copy(value);
// }
