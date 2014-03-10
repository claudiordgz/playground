#ifndef NIGHTMARE_FILE_OPERATIONS_HPP
#define NIGHTMARE_FILE_OPERATIONS_HPP

template<class T>
void read_file(T const &filename, std::string &content)
{
  std::ifstream ifs(filename);
  content.append((std::istreambuf_iterator<char>(ifs)),
                 (std::istreambuf_iterator<char>()));
}

#endif
