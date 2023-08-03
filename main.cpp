#include <iostream>

#include "Algorithm.h"
#include "UnorderedMap.h"
#include "StreamIterator.h"

int main()
{
    std::cout << "-------------TEST1---------------\n";
    std::cout << "---------------------------------\n\n";

    std::pair<std::string, double> p1("RED", 1);
    std::pair<std::string, double> p2("GREEN", 2);
    std::pair<std::string, double> p3("BLUE", 3);
    UnorderedMap<std::string, double> umap;
    umap.Reserve(2);

    umap.Insert({ "RED", 1 });

    std::cout << "------------METHODS--------------\n";
    std::cout << "---------------------------------\n\n";
    std::cout << "Max Load Factor: " << umap.MaxLoadFactor() << std::endl;
    std::cout << "Load Factor: " << umap.LoadFactor() << std::endl;
    std::cout << "Elements Amount: " << umap.Size() << std::endl;
    std::cout << "Buckets Amount: " << umap.Depth() << std::endl;
    umap["PI"] = 3.14;
    std::cout << "---------------------------------\n";
    std::cout << "Max Load Factor: " << umap.MaxLoadFactor() << std::endl;
    std::cout << "Load Factor: " << umap.LoadFactor() << std::endl;
    std::cout << "Elements Amount: " << umap.Size() << std::endl;
    std::cout << "Buckets Amount: " << umap.Depth() << std::endl;
    umap["root2"] = 1.414;
    std::cout << "---------------------------------\n";
    umap.MaxLoadFactor(0.85);
    std::cout << "Max Load Factor: " << umap.MaxLoadFactor() << std::endl;
    std::cout << "Load Factor: " << umap.LoadFactor() << std::endl;
    std::cout << "Elements Amount: " << umap.Size() << std::endl;
    std::cout << "Buckets Amount: " << umap.Depth() << std::endl;
    umap["root3"] = 1.732;
    std::cout << "---------------------------------\n";
    std::cout << "Max Load Factor: " << umap.MaxLoadFactor() << std::endl;
    std::cout << "Load Factor: " << umap.LoadFactor() << std::endl;
    std::cout << "Elements Amount: " << umap.Size() << std::endl;
    std::cout << "Buckets Amount: " << umap.Depth() << std::endl;
    umap["exp"] = 1.1;
    std::cout << "---------------------------------\n";
    std::cout << "Max Load Factor: " << umap.MaxLoadFactor() << std::endl;
    std::cout << "Load Factor: " << umap.LoadFactor() << std::endl;
    std::cout << "Elements Amount: " << umap.Size() << std::endl;
    std::cout << "Buckets Amount: " << umap.Depth() << std::endl;
    umap["log10"] = 2.302;
    std::cout << "---------------------------------\n";
    std::cout << "Max Load Factor: " << umap.MaxLoadFactor() << std::endl;
    std::cout << "Load Factor: " << umap.LoadFactor() << std::endl;
    std::cout << "Elements Amount: " << umap.Size() << std::endl;
    std::cout << "Buckets Amount: " << umap.Depth() << std::endl;
    umap["e"] = 2.72;
    std::cout << "---------------------------------\n";
    std::cout << "Max Load Factor: " << umap.MaxLoadFactor() << std::endl;
    std::cout << "Load Factor: " << umap.LoadFactor() << std::endl;
    std::cout << "Elements Amount: " << umap.Size() << std::endl;
    std::cout << "Buckets Amount: " << umap.Depth() << std::endl;
    umap["Golden ratio"] = 1.618;
    std::cout << "---------------------------------\n";
    std::cout << "Max Load Factor: " << umap.MaxLoadFactor() << std::endl;
    std::cout << "Load Factor: " << umap.LoadFactor() << std::endl;
    std::cout << "Elements Amount: " << umap.Size() << std::endl;
    std::cout << "Buckets Amount: " << umap.Depth() << std::endl;
    umap["Khinchin's constant"] = 2.684;
    std::cout << "---------------------------------\n";
    std::cout << "Max Load Factor: " << umap.MaxLoadFactor() << std::endl;
    std::cout << "Load Factor: " << umap.LoadFactor() << std::endl;
    std::cout << "Elements Amount: " << umap.Size() << std::endl;
    std::cout << "Buckets Amount: " << umap.Depth() << std::endl;
    umap["The Glaisher Kinkelin constant"] = 1.282;
    std::cout << "---------------------------------\n";
    std::cout << "Max Load Factor: " << umap.MaxLoadFactor() << std::endl;
    std::cout << "Load Factor: " << umap.LoadFactor() << std::endl;
    std::cout << "Elements Amount: " << umap.Size() << std::endl;
    std::cout << "Buckets Amount: " << umap.Depth() << std::endl;
    umap["root5"] = 2.236;
    std::cout << "---------------------------------\n";
    std::cout << "Max Load Factor: " << umap.MaxLoadFactor() << std::endl;
    std::cout << "Load Factor: " << umap.LoadFactor() << std::endl;
    std::cout << "Elements Amount: " << umap.Size() << std::endl;
    std::cout << "Buckets Amount: " << umap.Depth() << std::endl;
    umap["Euler Mascheroni constant"] = 0.5772;
    std::cout << "---------------------------------\n";
    std::cout << "Max Load Factor: " << umap.MaxLoadFactor() << std::endl;
    std::cout << "Load Factor: " << umap.LoadFactor() << std::endl;
    std::cout << "Elements Amount: " << umap.Size() << std::endl;
    std::cout << "Buckets Amount: " << umap.Depth() << std::endl;
    umap["Meissel Mertens constant"] = 0.26149;
    std::cout << "---------------------------------\n";
    std::cout << "Max Load Factor: " << umap.MaxLoadFactor() << std::endl;
    std::cout << "Load Factor: " << umap.LoadFactor() << std::endl;
    std::cout << "Elements Amount: " << umap.Size() << std::endl;
    std::cout << "Buckets Amount: " << umap.Depth() << std::endl;
    umap["Bernstein's constant"] = 0.28016;
    std::cout << "---------------------------------\n";
    std::cout << "Max Load Factor: " << umap.MaxLoadFactor() << std::endl;
    std::cout << "Load Factor: " << umap.LoadFactor() << std::endl;
    std::cout << "Elements Amount: " << umap.Size() << std::endl;
    std::cout << "Buckets Amount: " << umap.Depth() << std::endl;

    UnorderedMap<std::string, double> umap2(std::move(umap));

    std::cout << "\n-------------ERASE---------------\n";
    std::cout << "---------------------------------\n\n";

    umap2.Erase("root2");
    UnorderedMap<std::string, double>::iterator iterok = umap2.begin();
    iterok += 1;
    umap2.Erase(iterok);

    std::cout << umap2["PI"] << std::endl;
    std::cout << umap2["root2"] << std::endl;
    std::cout << umap2["root3"] << std::endl;
    std::cout << umap2["exp"] << std::endl;
    std::cout << umap2["log10"] << std::endl;
    std::cout << umap2["e"] << std::endl;
    std::cout << umap2["Golden ratio"] << std::endl;
    std::cout << umap2["Khinchin's constant"] << std::endl;
    std::cout << umap2["The Glaisher–Kinkelin constant"] << std::endl;
    std::cout << umap2["root5"] << std::endl;
    std::cout << umap2["Euler–Mascheroni constant"] << std::endl;
    std::cout << umap2["Meissel–Mertens constant"] << std::endl;
    std::cout << umap2["Bernstein's constant"] << std::endl;

    std::cout << "\n---------------AT----------------\n";
    std::cout << "---------------------------------\n\n";

    std::cout << umap2.at("exp") << std::endl;

    std::cout << "\n--------------INSERT-------------\n";
    std::cout << "---------------------------------\n\n";

    umap2.Insert(p2);
    umap2.Insert_move(std::move(p3));

    std::cout << umap2["RED"] << std::endl;
    std::cout << umap2["GREEN"] << std::endl;
    std::cout << umap2["BLUE"] << std::endl;
    std::cout << umap2["YELLOW"] << std::endl;

    std::cout << "\n------------ITERATORS------------\n";
    std::cout << "------------CREATING-------------\n\n";

    UnorderedMap<std::string, double>::iterator iter_b = umap2.begin();
    UnorderedMap<std::string, double>::iterator iter_e = umap2.end();

    UnorderedMap<std::string, double> umap_iter(iter_b, iter_e);
    std::cout << "Max Load Factor: " << umap_iter.MaxLoadFactor() << std::endl;
    std::cout << "Load Factor: " << umap_iter.LoadFactor() << std::endl;
    std::cout << "Elements Amount: " << umap_iter.Size() << std::endl;
    std::cout << "Buckets Amount: " << umap_iter.Depth() << std::endl;

    std::cout << "\n------------ITERATORS------------\n";
    std::cout << "-------------OUTPUT--------------\n\n";

    int count = 0;
    for (auto iter = iter_b; iter != iter_e; ++iter) {
        try { std::cout << iter.first() << " " << iter.second() << " at iter " << count << std::endl; }
        catch (Exception) { continue; }
        count++;
    }

    std::cout << "\n------------ITERATORS------------\n";
    std::cout << "-------------MAX/MIN-------------\n\n";

    iter_b = umap2.begin();
    iter_e = umap2.end();
    UnorderedMap<std::string, double>::iterator EXPITERALGMAX = maxElement<UnorderedMap<std::string, double>::iterator>(iter_b, iter_e);
    auto EXPITERALGMIN = minElement(iter_b, iter_e);
    std::cout << EXPITERALGMAX.first() << " " << EXPITERALGMAX.second() << std::endl;
    std::cout << EXPITERALGMIN.first() << " " << EXPITERALGMIN.second() << std::endl;

    std::cout << "\n--------------EMPTY--------------\n";
    std::cout << "--------------CLEAR--------------\n\n";

    std::cout << umap2.Empty() << std::endl;
    umap2.Clear();
    std::cout << umap2.Empty() << std::endl;

    std::cout << "\n---------------------------------\n";
    std::cout << "---------------------------------\n\n";

    std::cout << "-------------TEST2---------------\n";
    std::cout << "---------------------------------\n\n";

    struct Goods {
        uint32_t    m_id;                // Код товара
        std::string m_name;              // Название
        std::string m_manufacturer;      // Производитель
        std::string m_warehouse_address; // Адрес склада
        double      m_weight;            // Вес
    };

    Goods g1;
    g1.m_id = 71;
    g1.m_name = "NAME";

    UnorderedMap<std::string, uint32_t> cont_1{ {g1.m_name,g1.m_id},{"test_text",123} };
    auto it1_b = cont_1.begin();
    auto it1_e = cont_1.end();
    auto print1 = [](UnorderedMap<std::string, uint32_t>::iterator iter) {std::cout << iter.second() << " - " << iter.first() << "   ";};
    std::cout << "cont_1 contains:\n";
    forEach(it1_b, it1_e, print1);
    std::cout << std::endl << std::endl;

    Goods g2;
    g2.m_weight = 0.431;
    g2.m_manufacturer = "MANUFACTURER";

    UnorderedMap<std::string, double> cont_1_1{ {"test_text",123.123}, {g2.m_manufacturer,g2.m_weight} };
    auto it1_1_b = cont_1_1.begin();
    auto it1_1_e = cont_1_1.end();
    auto print1_1 = [](UnorderedMap<std::string, double>::iterator iter) {std::cout << iter.second() << " - " << iter.first() << "   ";};
    std::cout << "cont_1_1 contains:\n";
    forEach(it1_1_b, it1_1_e, print1_1);
    std::cout << std::endl << std::endl;

    std::cout << "---------------------------------\n";
    std::cout << "---------------------------------\n\n";

    Goods g3({ 213 }, { "name1" }, { "manuf1" }, { "address1" }, { 2.2222 });
    Goods g4({ 7 }, { "name2" }, { "manuf2" }, { "address2" }, { 5.1 });
    Goods g5({ 457454 }, { "name3" }, { "manuf3" }, { "t_address3" }, { 0.123 });

    UnorderedMap<std::string, uint32_t> cont_2;
    cont_2.Insert(std::make_pair(g3.m_name, g3.m_id));
    cont_2.Insert(std::make_pair(g4.m_manufacturer, g4.m_id));
    cont_2.Insert(std::make_pair(g5.m_warehouse_address, g5.m_id));
    cont_2.Insert(std::make_pair("some_name1", g3.m_id));

    auto it2_b = cont_2.begin();
    auto it2_e = cont_2.end();
    auto print2 = [](UnorderedMap<std::string, uint32_t>::iterator iter) {std::cout << iter.second() << " - " << iter.first() << "   ";};
    std::cout << "cont_2 contains:\n";
    forEach(it2_b, it2_e, print2);
    std::cout << std::endl << std::endl;

    std::cout << "---------------------------------\n";
    std::cout << "---------------------------------\n\n";

    std::cout << "find if weight == 0.431\n";
    auto predicat = [](double numb) {return (numb == 0.431);};
    auto res_iter = findIf(it1_1_b, it1_1_e, predicat);
    std::cout << res_iter.second() << " - " << res_iter.first() << std::endl;
    std::cout << std::endl;

    std::cout << "---------------------------------\n";
    std::cout << "---------------------------------\n\n";

    res_iter.second() = "NEWMANUFACTURER";
    std::cout << "new cont_1_1 contains:\n";
    forEach(it1_1_b, it1_1_e, print1_1);
    std::cout << std::endl << std::endl;

    std::cout << "---------------------------------\n";
    std::cout << "---------------------------------\n\n";

    struct my_functor {
        my_functor(uint32_t numb) : field(numb) {}
        bool operator()(uint32_t numb) { return field == numb; }
    private:
        uint32_t field;
    };

    UnorderedMap<std::string, uint32_t> copied_cont(cont_2.Depth());

    auto it_c = copyIf(it2_b, it2_e, copied_cont.begin(), my_functor(213));

    std::cout << "copied container with only id's of 213 contains:\n";
    forEach(copied_cont.begin(), copied_cont.end(), print2);
    // It contains nothing because my hash needs a separate copyIf realisation and additional overloading;

    std::cout << "\n-------------TEST3---------------\n";
    std::cout << "---------------------------------\n\n";

    copy(it2_b, it2_e, OstreamIterator<uint32_t>(std::cout, ' '));
    // Only DataType

    std::cout << std::endl;

    return 0;
}
