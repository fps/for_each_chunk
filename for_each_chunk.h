#ifndef FOR_EACH_CHUNK_INCLUDED_HH
#define FOR_EACH_CHUNK_INCLUDED_HH

/**
 * Iterator must be a random access iterator
 */
template<class Iterator, class Functor>
inline void for_each_chunk(Iterator begin, Iterator end, unsigned int chunk_size, Functor f) {
	unsigned int num_of_chunks = (end - begin) / chunk_size;
	unsigned int remainder = (end - begin) % chunk_size;
	
	/*
	 * Handle "normal" chunks
	 */
	for (unsigned int index = 0; index < num_of_chunks; ++index)
	{
		f(begin + chunk_size * index, begin + chunk_size * (index + 1));
	}
	
	/*
	 * Handle remainder
	 */
	if (0 != remainder)
	{
		f(begin + chunk_size * num_of_chunks, end);
	}
}

#endif
