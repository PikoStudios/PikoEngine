import { Box, Flex } from "@chakra-ui/core"
import NextLink from 'next/link';
import React from "react"


const Index = () => (
  <Box bg="rgb(52, 60, 75)" w="100%" p={4} color="white">
    Piko Engine
    <NextLink href="/docs/getting-started">Getting Started</NextLink>
    <NextLink href="/downloads/">Download</NextLink>
  </Box>
)

export default Index
