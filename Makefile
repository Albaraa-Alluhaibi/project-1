msg:
	@echo 'Targets are: '
	@echo ' producer'
	@echo ' consumer'
	@echo ' run'
	@echo  ' clean'




consumer: ./cpp/consumer.cpp
	g++ "./cpp/consumer.cpp" -pthread -lrt -o ./output/consumer


producer: ./cpp/producer.cpp
	g++ "./cpp/producer.cpp" -pthread -lrt -o ./output/producer



